#include <string>
#include <iostream>

int main(){
  const std::string red("\033[0;36m");
  const std::string r("\033[0;31m");
  const std::string reset("\033[0m");
  
  std::cout << red << "STARTING SKEW EXPERIMENT\n\n";
  
  std::string skew = "./skew_experiment -p Skew_Experiment/param_sets.csv -e " " -d Skew_Experiment/init_conc.csv -t 10 -u 1.0 -c 10 -w 1";
  int skew_exp = system(skew.c_str());
  
  std::cout << red << "STARTING DENSITY EXPERIMENT\n\n";
  
  std::string density = "./density_experiment -e " " -d Density_Experiment/init_conc.csv -p Density_Experiment/param_sets.csv -t 10 -u 1.0 -c 10 -w 3";
  int den_exp = system(density.c_str());
  
  std::cout << red << "STARTING EXPONENTIAL EXPERIMENT\n\n";
  
  std::string exp = "./exponential_experiment -p Exponential_Experiment/param_sets.csv -e " " -d Exponential_Experiment/init_conc.csv -t 10 -u 1.0 -c 10 -w 1";
  int exp_exp = system(exp.c_str());
  
  std::cout << red << "STARTING OSCILLATING EXPERIMENT\n\n";
  
  std::string oscillating = "./oscillating_experiment -p Oscillating_Experiment/param_sets.csv -d Oscillating_Experiment/init_conc.csv -e " " -t 10 -u 1.0 -c 10 -w 1";
  int osc_exp = system(oscillating.c_str());
  
  std::cout << red << "STARTING OVERHEAD EXPERIMENT\n\n";
  
  std::string overhead = "./overhead_experiment -p Overhead_Experiment/param_sets.csv -e " " -d Overhead_Experiment/init_conc.csv -t 10 -u 1.0 -c 10 -w 1";
  int ove_exp = system(overhead.c_str());
  
  std::cout << red << "STARTING SCALE EXPERIMENT\n\n";
  
  std::string scale = "./scale_experiment -p Scale_Experiment/param_sets.csv -e " " -d Scale_Experiment/init_conc.csv -t 10 -u 1.0 -c 10 -w 1";
  int sca_exp = system(scale.c_str());
  
  int num_passed = skew_exp + den_exp + exp_exp + osc_exp + ove_exp + sca_exp;
  std::cout << red << "Passed: " << 6 - num_passed << " / " << 6 << std::endl << reset;
  if(num_passed != 0){
    std::cout << r << "Failed: ";
    if(skew_exp != 0){
      std::cout << "Skew Test, ";
    }if(den_exp != 0){
      std::cout << "Density Test, ";
    }if(exp_exp != 0){
      std::cout << "Exponential Test, ";
    }if(osc_exp != 0){
      std::cout << "Oscillating Test, ";
    }if(ove_exp != 0){
      std::cout << "Overhead Test, ";
    }if(sca_exp != 0){
      std::cout << "Scale Test, ";
    }
    std::cout << reset << "\n";
  }
  return num_passed;
}
