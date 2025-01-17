#include "io/arg_parse.hpp"
#include "utility/style.hpp"
#include "utility/common_utils.hpp"
#include "sim/determ/determ.hpp"
#include "sim/stoch/fast_gillespie_direct_simulation.hpp"
#include "sim/stoch/next_reaction_simulation.hpp"
#include "sim/stoch/rejection_based_simulation.hpp"
#include "sim/stoch/Gillespie_Direct_Simulation.hpp"
#include "sim/stoch/log_direct_method.hpp"
#include "model_impl.hpp"
#include "Sim_Builder.hpp"
#include "run_simulation.hpp"
#include "arg_parse.hpp"
#include "../experiments_utility.hpp"
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
using dense::Stochastic_Simulation;
using dense::Log_Direct_Simulation;
using dense::Rejection_Based_Simulation;
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
  std::vector<std::vector<Real>> perf;
  std::string perf_sims = "";
  
  std::cout << style::apply(Color::yellow) << "Starting the Fast Gillespie Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Fast_Gillespie_Direct_Simulation>(ac, av, &args, "Fast_Gillespie_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Fast Gillespie Simulation\n\n";
  perf_sims += "Fast Gillespie,";
  
  std::cout << "Starting the Gillespie Direct Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Stochastic_Simulation>(ac, av, &args, "Gillespie_Direct_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Gillespie Direct Simulation\n\n";
  perf_sims += "Gillespie Direct,";

  std::cout << "Starting the Rejection Based Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Rejection_Based_Simulation>(ac, av, &args, "Rejection_Based_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Rejection Based Simulation\n\n";
  perf_sims += "Rejection,";
  
#if 0
  std::cout << "Starting the Anderson Next Reaction Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Anderson_Next_Reaction_Simulation>(ac, av, &args, "Anderson_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Anderson Next Reaction Simulation\n\n";
  perf_sims += "Anderson Next Reaction,";
#endif
// 
  std::cout << "Starting the Next Reaction Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Next_Reaction_Simulation>(ac, av, &args, "Next_Reaction_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Next Reaction Simulation\n\n";
  perf_sims += "Next Reaction,";
  
  std::cout << "Starting the Sorting Direct Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Sorting_Direct_Simulation>(ac, av, &args, "Sorting_Direct_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Sorting Direct Simulation\n\n" << style::reset();
  perf_sims += "Sorting Direct,";
  
  std::cout << "Starting the Log Direct Simulation\n" << style::reset();
  perf.push_back(simulate_experiment<Log_Direct_Simulation>(ac, av, &args, "Log_Direct_Oscillating"));
  std::cout << style::apply(Color::yellow) << "Finished the Log Direct Simulation\n\n" << style::reset();
  perf_sims += "Log Direct,";
  
  performance_out("Oscillating", perf, perf_sims);
}

//PARAMS USING: ./oscillating_experiment -p Oscillating_Experiment/param_sets.csv -d Oscillating_Experiment/init_conc.csv -e " " -t 10 -u 1.0 -c 100 -w 1 -s 1.0
