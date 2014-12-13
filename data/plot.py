import pylab

list_of_files = [("cv.txt", "data"),("cv2.txt", "data2")]

datalist = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files ]

for data, label in datalist:
    pylab.plot( data[:,0], data[:,1], label=label )

#pylab.legend()
pylab.title("16x16 | 40 mcs | 5000 samples")
pylab.xlabel("kT/J")
pylab.ylabel("C_v/(N*k)")
pylab.grid();

pylab.show()