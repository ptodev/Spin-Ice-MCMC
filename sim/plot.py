import pylab

# list_of_files = [("data.txt", "100x100 | 100 mcs | 100 samples | beta = 1/4")]
#                  ("data2.txt", "100x100 | 100 mcs | 100 samples | beta = 1/2.2")]

list_of_files = [("data.txt",  "100x100 | 500 mcs | 250 samples | beta = 1/1.5"),
                 ("data2.txt", "100x100 | 500 mcs | 250 samples | beta = 1/2.2")]

datalist = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files ]

for data, label in datalist:
    pylab.plot( data[:,0], data[:,1], label=label )

# pylab.legend()
# pylab.title("")
pylab.legend(loc='center')
pylab.xlabel("mcs")
pylab.ylabel("betaJ * E")
pylab.grid();

pylab.show()