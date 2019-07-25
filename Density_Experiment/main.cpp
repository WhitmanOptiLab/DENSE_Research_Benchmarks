#include "io/arg_parse.hpp"
#include "utility/style.hpp"
#include "utility/common_utils.hpp"
#include "sim/determ/determ.hpp"
#include "sim/stoch/fast_gillespie_direct_simulation.hpp"
#include "sim/stoch/next_reaction_simulation.hpp"
#include "sim/stoch/rejection_based_simulation.hpp"
#include "sim/stoch/Gillespie_Direct_Simulation.hpp"
#include "sim/stoch/anderson_next_reaction_simulation.hpp"
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
using dense::parse_static_args;
using dense::Static_Args;


NGraph::Graph create_dense_graph(dense::Natural cell_total){
  NGraph::Graph dense_graph;
  for(dense::Natural cell = 0; cell < cell_total; cell++){
    for(dense::Natural neigh = 0; neigh < cell_total; neigh++){
      if(neigh != cell){
        dense_graph.insert_edge(cell,neigh);
      }
    }
  }
  return dense_graph;
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
  int cell_total = args.adj_graph.num_vertices();
  
  args.adj_graph = std::move(create_dense_graph(cell_total));
  
  std::cout << style::apply(Color::yellow) << "Starting the Fast Gillespie Simulation\n" << style::reset();
  simulate_experiment<Fast_Gillespie_Direct_Simulation>(ac, av, &args, "Density_Experiment/Fast_Gillespie_Density");
  std::cout << style::apply(Color::yellow) << "Finished the Fast Gillespie Simulation\n\n";
  
  std::cout << "Starting the Gillespie Direct Simulation\n" << style::reset();
  simulate_experiment<Stochastic_Simulation>(ac, av, &args, "Density_Experiment/Gillespie_Direct_Density");
  std::cout << style::apply(Color::yellow) << "Finished the Gillespie Direct Simulation\n\n";
  
  std::cout << "Starting the Anderson Next Reaction Simulation\n" << style::reset();
  simulate_experiment<Anderson_Next_Reaction_Simulation>(ac, av, &args, "Density_Experiment/Anderson_Density");
  std::cout << style::apply(Color::yellow) << "Finished the Anderson Next Reaction Simulation\n\n";
  
  std::cout << "Starting the Rejection Based Simulation\n" << style::reset();
  simulate_experiment<Rejection_Based_Simulation>(ac, av, &args, "Density_Experiment/Rejection_Based_Density");
  std::cout << style::apply(Color::yellow) << "Finished the Rejection Based Simulation\n\n" << style::reset();
  
//  std::cout << "Starting the Next Reaction Simulation\n" << style::reset();
//  simulate_experiment<Next_Reaction_Simulation>(ac, av, &args, "Overhead_Experiment/Next_Reaction_Overhead");
//  std::cout << style::apply(Color::yellow) << "Finished the Next Reaction Simulation\n" << style::reset();
}


//PARAMS USING: ./density_experiment -e " " -d Density_Experiment/init_conc.csv -p Density_Experiment/param_sets.csv -t 10 -u 1.0 -c 10 -w 3 -s 0.1

