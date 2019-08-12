#include <string>
#include <iostream>

int main(){
  const std::string red("\033[0;36m");
  const std::string r("\033[0;31m");
  const std::string reset("\033[0m");
  int num_passed = 0;
  
  std::cout << red << "STARTING SMALL CONCENTRATIONS EXPERIMENT\n\n";
  std::string conc = "./conc_experiment -p Conc_Experiment/param_sets.csv -e " " -d Conc_Experiment/init_conc.csv -t 2000 -u 2000 -c 500 -w 1";
  int conc_exp = system(conc.c_str());
  if(conc_exp == 0){num_passed += 1;}
  
  std::cout << red << "STARTING DENSITY EXPERIMENT\n\n";
  
  std::string density = "./density_experiment -e " " -d Density_Experiment/init_conc.csv -p Density_Experiment/param_sets.csv -t 10 -u 10 -c 150 -w 1";
  int den_exp = system(density.c_str());
  if(den_exp == 0){num_passed += 1;}
  
  std::cout << red << "STARTING EXPONENTIAL EXPERIMENT\n\n";
  
  std::string exp = "./exponential_experiment -p Exponential_Experiment/param_sets.csv -e " " -d Exponential_Experiment/init_conc.csv -t 10 -u 10 -c 150 -w 1";
  int exp_exp = system(exp.c_str());
  if(exp_exp == 0){num_passed += 1;}
  
  std::cout << red << "STARTING OSCILLATING EXPERIMENT\n\n";
  
  std::string oscillating = "./oscillating_experiment -p Oscillating_Experiment/param_sets.csv -d Oscillating_Experiment/init_conc.csv -e " " -t 20 -u 20 -c 100 -w 1";
  int osc_exp = system(oscillating.c_str());
  if(osc_exp == 0){num_passed += 1;}
  
  std::cout << red << "STARTING OVERHEAD EXPERIMENT\n\n";
  
  std::string overhead = "./overhead_experiment -p Overhead_Experiment/param_sets.csv -e " " -d Overhead_Experiment/init_conc.csv -t 10000 -u 10000 -c 10 -w 1";
  int ove_exp = system(overhead.c_str());
  if(ove_exp == 0){num_passed += 1;}
  
  std::cout << red << "STARTING SCALE EXPERIMENT\n\n";
  
  std::string scale = "./scale_experiment -p Scale_Experiment/param_sets.csv -e " " -d Scale_Experiment/init_conc.csv -t 10 -u 10 -c 20 -w 1";
  int sca_exp = system(scale.c_str());
  if(sca_exp == 0){num_passed += 1;}
  
  
  std::cout << red << "Passed: " << num_passed << " / " << 6 << std::endl << reset;
  if(num_passed != 6){
    std::cout << r << "Failed: ";
    if(conc_exp != 0){
      std::cout << "Conc Test, ";
    }if(den_exp != 0){
      std::cout << "Density Test, ";
    }if(exp_exp != 0){
      std::cout << "Exponential Test, ";
    }if(osc_exp != 0){
      std::cout << "Oscillating Test, ";
    }if(ove_exp != 0){
      std::cout << "Overhead Test, ";
    }if(sca_exp != 0){
      std::cout << "Scale Test ";
    }
    std::cout << reset << "\n";
  }
  
  std::cout << reset;
  
//   std::string graph = "python3 graphmaker.py \"performance/Conc_performance.csv\" \"Conc\"";
  std::string graph = "python3 graphmaker.py \"performance/Exponential_performance.csv\" \"performance/Conc_performance.csv\" \"performance/Density_performance.csv\" \"performance/Oscillating_performance.csv\" \"performance/Scale_performance.csv\" \"performance/Overhead_performance.csv\" \"Data\" ";
  system(graph.c_str());
  
//   graph = "python3 graphmaker.py \"performance/Density_performance.csv\" \"Density\"";
//   system(graph.c_str());
  
//   graph = "python3 graphmaker.py \"performance/Exponential_performance.csv\" \"Exponential\"";
//   system(graph.c_str());
  
//   graph = "python3 graphmaker.py \"performance/Oscillating_performance.csv\" \"Oscillating\"";
//   system(graph.c_str());
  
//   graph = "python3 graphmaker.py \"performance/Overhead_performance.csv\" \"Overhead\"";
//   system(graph.c_str());
  
//   graph = "python3 graphmaker.py \"performance/Scale_performance.csv\" \"Scale\"";
  system(graph.c_str());


  return num_passed;
}
