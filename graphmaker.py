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
                    ha='center', va='bottom')

def main():
  sim_names = []
  sim_data = []
  
  with open(sys.argv[1]) as csvfile:
    graph_data = csv.reader(csvfile, delimiter=",")
    line_count = 0
    for row in graph_data:
      if line_count == 0:
        sim_names = row
        line_count += 1
      else:
        sim_data.append(row)
        line_count +=1
      print(f'processed {line_count} line(s).')
  x = np.arange(len(sim_names))
  width = 0.15
  
  sim_data_nums  = []
  for i in range(len(sim_data)):
    temp = []
    for j in range(len(sim_data[i])):
      temp.append(float(sim_data[i][j]))
    sim_data_nums.append(temp)
  
  
  
  fig, ax = plt.subplots()
  rects = [] 
  num_data =  ((len(sim_data_nums)/4)*-1)*width
  count = 1
  for d in sim_data_nums:
    if (num_data == 0):
      div = 0
    else:  
      div = width/num_data
    rects1 = ax.bar(x + num_data, d, width, label=f'Entry {count}')
    rects.append(rects1)
    num_data += width
    count += 1
  ax.set_ylabel('Reactions/Second')
  ax.set_title(sys.argv[2])
  ax.set_xticks(x)
  ax.set_xticklabels(sim_names)
  ax.legend()
  
  for r in rects:
    autolabel(r, ax)
  
  
  fig.tight_layout()
  
  plt.show()
  
main()
  
  

