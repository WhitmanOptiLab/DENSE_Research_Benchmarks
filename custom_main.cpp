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
//#include "time_simulation.hpp"

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
#include <ratio>
#include <ctime>

using dense::csvw_sim;
using dense::stochastic::Next_Reaction_Simulation;
using dense::Sim_Builder;
//using dense::Stochastic::Simulation;
using dense::Fast_Gillespie_Direct_Simulation;
using dense::parse_static_args;
using dense::parse_analysis_entries;
using dense::Static_Args;
using dense::run_simulation;
//using dense::time_simulation;


int main(int argc, char* argv[]){
  arg_parse::init(argc, argv);
  //Parse static arguments 
  Static_Args args = parse_static_args(argc, argv);
  if(args.help == 1){
    return EXIT_SUCCESS;
  }
  if(args.help == 2){
    return EXIT_FAILURE;
  }
  
  int num_trials;
  if(!arg_parse::get<int>("nt", "num-trials", &num_trials, true)){
    std::cout << "please enter number of trials \n";
    return EXIT_FAILURE;
  }
  
  std::string cell_counts;
  if(!arg_parse::get<std::string>("cc", "cell-counts", &cell_counts, true)){
    std::cout << "ERROR: invalid file \n";
    return EXIT_FAILURE;
  }
  
  csvr csv_in(cell_counts);
  
  std::vector<Natural> cell_total_list;
  Natural entry = -1;
  Natural *data_getter = &entry;
  
  
  if(!csv_in.get_next(data_getter)){
		std::cout << style::apply(Color::red) << "Error, data submitted is misformatted \n" << style::reset();
	}

	cell_total_list.push_back(*data_getter);
	
	while(csv_in.get_next(data_getter)){
		cell_total_list.push_back(*data_getter);
  }
  
  Real trial_num = 0;
  
  csvw csv_out("benchmark_data.csv");
  csv_out.add_div("Trial, ");
  csv_out.add_div("Number of Cells, ");
  csv_out.add_div("Next Reaction, ");
  csv_out.add_div("Slow Gillespie, ");
  csv_out.add_div("Fast Gillespie, \n");
  
  for(auto ct : cell_total_list){
    
    
    for(int j = 0; j < num_trials; j++){
      
      trial_num++;
      csv_out.add_data(trial_num);
      double  ct_double = (double)(ct * 1.0);
      csv_out.add_data(ct_double);
      
      std::chrono::duration<double> next_reaction_time = time_simulation<Next_Reaction_Simulation>(args, ct, argc, argv);
      
      std::chrono::duration<double> slow_gillespie_time = time_simulation<Stochastic_Simulation>(args, ct, argc, argv);
      
      std::chrono::duration<double> fast_gillespie_time = time_simulation<Fast_Gillespie_Direct_Simulation>(args, ct, argc, argv);
      csv_out.add_data(next_reaction_time.count());
      csv_out.add_data(slow_gillespie_time.count()); 
      csv_out.add_data(fast_gillespie_time.count());
      csv_out.add_div("\n");
      
    }
  }
}


/*
Snapshot<> snapshot;
Snapshot<> data = simulation.snapshot();
template <typename Simulation>
Real Reaction_Traits<ph1_synthesis>::calculate_rate_for(Region<Simulation> region) {
}
*/