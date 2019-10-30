import pickle


def main():
  fp = open('greeneggs_tagged.dat', 'rb')
  data = pickle.load(fp)
  print(data)


if __name__ == '__main__':
  main()