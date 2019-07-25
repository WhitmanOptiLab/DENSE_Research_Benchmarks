#include "io/arg_parse.hpp"
#include "utility/style.hpp"
#include "utility/common_utils.hpp"
#include "sim/determ/determ.hpp"
#include "sim/stoch/fast_gillespie_direct_simulation.hpp"
#include "sim/stoch/next_reaction_simulation.hpp"
#include "sim/stoch/rejection_based_simulation.hpp"
//#include "sim/stoch/Gillespie_Direct_Simulation.hpp"
#include "model_impl.hpp"
#include "Sim_Builder.hpp"
#include "run_simulation.hpp"
#include "arg_parse.hpp"
#include "../simulate_experiment.hpp"

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
  simulate_experiment<Fast_Gillespie_Direct_Simulation>(ac, av, &args, "Scale_Experiment/Fast_Gillespie_Scale");
  std::cout << style::apply(Color::yellow) << "Finished the Fast Gillespie Simulation\n\n";
  
//  std::cout << "Starting the Stochastic Simulation\n" << style::reset();
//  simulate_experiment<Stochastic_Simulation>(ac, av, &args, "Scale_Experiment/Stochastic_Scale");
//  std::cout << style::apply(Color::yellow) << "Finished the Stochastic Simulation\n\n";
  
//  std::cout << "Starting the Anderson Next Reaction Simulation\n" << style::reset();
//  simulate_experiment<Anderson_Next_Reaction_Simulation>(ac, av, &args, "Scale_Experiment/Anderson_Scale");
//  std::cout << style::apply(Color::yellow) << "Finished the Anderson Next Reaction Simulation\n\n";
  
  std::cout << "Starting the Rejection Based Simulation\n" << style::reset();
  simulate_experiment<Rejection_Based_Simulation>(ac, av, &args, "Scale_Experiment/Rejection_Based_Scale");
  std::cout << style::apply(Color::yellow) << "Finished the Rejection Based Simulation\n\n"  << style::reset();
  
  
//  std::cout << "Starting the Next Reaction Simulation\n" << style::reset();
//  simulate_experiment<Next_Reaction_Simulation>(ac, av, &args, "Scale_Experiment/Next_Reaction_Scale");
//  std::cout << style::apply(Color::red) << "Error: could not run\n" << style::reset();
//  std::cout << style::apply(Color::yellow) << "Finished the Next Reaction Simulation\n" << style::reset();
}

//PARAMS USING: ./scale_experiment -p Scale_Experiment/param_sets.csv -e " " -d Scale_Experiment/init_conc.csv -t 10 -u 1.0 -c 100 -w 1 -s 1.0