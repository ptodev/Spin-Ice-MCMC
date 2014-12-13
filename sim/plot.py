import pylab

list_of_files = [("data.txt", "data")]

datalist = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files ]

for data, label in datalist:
    pylab.plot( data[:,0], data[:,1], label=label )

# pylab.legend()
pylab.title("100x100 | 100 mcs | 100 samples | beta = 1/3")
pylab.xlabel("mcs")
pylab.ylabel("E*beta")
pylab.grid();

pylab.show()