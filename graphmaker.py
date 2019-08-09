import matplotlib 
import matplotlib.pyplot as plt
import numpy as np
import sys
import csv

def autolabel(rects, a):
  for rect in rects:
    height = rect.get_height()
    a.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom',size=5,rotation=90)

def main():
  sim_names = []
  sim_data = []
  sim_experiments = []
  for file in sys.argv[1:-1]:
    with open(file) as csvfile:
      sim_experiments.append(file[:-16])
      graph_data = csv.reader(csvfile, delimiter=",")
      line_count = 0
      for row in graph_data:
        if line_count == 0:
          sim_names = row
          line_count += 1
        else:
          sim_data.append(row)
          line_count +=1
  x = np.arange(0,14*len(sim_experiments),14)
  width = 2
  
  sim_data_nums  = []
  for i in sim_data:
    temp = []
    for j in i:
      temp.append(float(j))
    sim_data_nums.append(temp)
  
  
  fig, ax = plt.subplots()
  rects = []
  
  data = []
  
  num_data =  -5
  for i in range(len(sim_data_nums[0])):
    temp = []
    for j in range(len(sim_data_nums)):
      temp.append(sim_data_nums[j][i])
    data.append(temp)
  count = 1
  
  for d in data:
    rects1 = ax.bar(x + num_data, d, width, label= sim_names[count - 1])
    rects.append(rects1)
    num_data += width
    count += 1
  ax.set_ylabel('Reactions/Second')
  ax.set_title(sys.argv[-1])
  ax.set_xticks(x)
  ax.set_xticklabels(sim_experiments)
  ax.legend()
  
  for r in rects:
    autolabel(r, ax)
  
  
  fig.tight_layout()
  
  plt.show()
  
main()

#Command line arguements:
#python3 graphmaker.py Exponential_performance.csv Conc_performance.csv Density_performance.csv Oscillating_performance.csv Scale_performance.csv Overhead_performance.csv "Data"
