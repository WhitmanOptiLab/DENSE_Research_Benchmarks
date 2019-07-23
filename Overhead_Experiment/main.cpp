#include "io/arg_parse.hpp"
#include "measurement/oscillation.hpp"
#include "measurement/basic.hpp"
#include "measurement/bad_simulation_error.hpp"
#include "utility/style.hpp"
#include "utility/common_utils.hpp"
#include "io/csvr_sim.hpp"
#include "io/csvw_sim.hpp"
#include "sim/determ/determ.hpp"
#include "sim/stoch/fast_gillespie_direct_simulation.hpp"
#include "sim/stoch/next_reaction_simulation.hpp"
#include "model_impl.hpp"
#include "io/ezxml/ezxml.h"
#include "Sim_Builder.hpp"
#include "run_simulation.hpp"
#include "arg_parse.hpp"
#include "parse_analysis_entries.hpp"
#include "ngraph/ngraph.hpp"

using style::Color;

#include <chrono>
#include <cstdlib>
#include <cassert>
#include <random>
#include <memory>
#include <iterator>
#include <algorithm>
#include <functional>
#include <exception>
#include <iostream>

using dense::csvw_sim;
using dense::Fast_Gillespie_Direct_Simulation;
using dense::Sim_Builder;
using dense::parse_static_args;
using dense::parse_analysis_entries;
using dense::Static_Args;
using dense::run_simulation;

template<class Overhead_Simulation>
void simulate_overhead(int ac, char** av, Static_Args* args, std::string type){
  using Simulation = Scale_Simulation;
  Sim_Builder<Simulation> sim = Sim_Builder<Simulation>(args->perturbation_factors, args->gradient_factors, args->adj_graph, ac, av);
  std::vector<std::pair<std::string, std::unique_ptr<Analysis<Simulation>>>> names_and_analysis = parse_analysis_entries<Simulation>(ac, av, args->adj_graph.num_vertices());
  for(auto& entry : names_and_analysis){
    entry.first = "Overhead_Experiment/" + type + ".csv";
  }
  run_simulation<Simulation>(args->simulation_duration, args->analysis_interval, std::move(sim.get_simulations(args->param_sets)), std::move(names_and_analysis));
}

int main(int argc, char* argv[]){
  int ac = argc;
  char** av = argv;

  Static_Args args = parse_static_args(argc, argv);
  if(args.help == 1){
    return EXIT_SUCCESS;
  }
  if(args.help == 2){
    return EXIT_FAILURE;
  }
  
  std::cout << style::apply(Color::yellow) << "Starting the Fast Gillespie Simulation\n" << style::reset();
  
  overhead_scale<Fast_Gillespie_Direct_Simulation>(ac, av, &args, "Fast_Gillespie_Overhead");
  
  std::cout << style::apply(Color::yellow) << "Finished the Fast Gillespie Simulation\n\n";
  std::cout << "Starting the Deterministic Simulation\n" << style::reset();
  
  overhead_scale<Deterministic_Simulation>(ac, av, &args, "Deterministic_Overhead");
  
  std::cout << style::apply(Color::yellow) << "Finished the Deterministic Simulation\n" << style::reset();
  std::cout << "Starting the Next Reaction Simulation\n" << style::reset();
  
  simulate_density<Next_Reaction_Simulation>(ac, av, &args, "Next_Reaction_Overhead");
  
  std::cout << "\n" << style::apply(Color::yellow) << "Finished the Next Reaction Simulation\n" << style::reset();
}



//PARAMS USING: ./scale_experiment -p Scale_Experiment/param_sets.csv" -t 10 -u 1.0 -c 10 -w 3 -s 1.0

