#include <string>
#include <iostream>

int main(){
  
  std::cout << "STARTING SKEW EXPERIMENT\n\n";
  
  std::string skew = "./skew_experiment -p Skew_Experiment/param_sets.csv -e " " -d Skew_Experiment/init_conc.csv -t 10 -u 1.0 -c 100 -w 1 -s 1.0";
  system(skew.c_str());
  
  std::cout << "\n\nSTARTING DENSITY EXPERIMENT\n\n";
  
  std::string density = "./density_experiment -e " " -d Density_Experiment/init_conc.csv -p Density_Experiment/param_sets.csv -t 10 -u 1.0 -c 10 -w 3 -s 0.1";
  system(density.c_str());
  
  std::cout << "\n\nSTARTING EXPONENTIAL EXPERIMENT\n\n";
  
  std::string exp = "./exponential_experiment -p Exponential_Experiment/param_sets.csv -e " " -d Exponential_Experiment/init_conc.csv -t 10 -u 1.0 -c 100 -w 1 -s 1.0";
  system(exp.c_str());
  
  std::cout << "\n\nSTARTING OSCILLATING EXPERIMENT\n\n";
  
  std::string oscillating = "./oscillating_experiment -p Oscillating_Experiment/param_sets.csv -d Oscillating_Experiment/init_conc.csv -e " " -t 10 -u 1.0 -c 100 -w 1 -s 1.0";
  system(oscillating.c_str());
  
  std::cout << "\n\nSTARTING OVERHEAD EXPERIMENT\n\n";
  
  std::string overhead = "./overhead_experiment -p Overhead_Experiment/param_sets.csv -e " " -d Overhead_Experiment/init_conc.csv -t 10 -u 1.0 -c 100 -w 1 -s 1.0";
  system(overhead.c_str());
  
  std::cout << "\n\nSTARTING SCALE EXPERIMENT\n\n";
  
  std::string scale = "./scale_experiment -p Scale_Experiment/param_sets.csv -e " " -d Scale_Experiment/init_conc.csv -t 10 -u 1.0 -c 100 -w 1 -s 1.0";
  system(scale.c_str());
  
  return 0;
}