import pylab

# list_of_files = [("cv.txt",  "16x16 | 40 mcs | 5000 samples"),
#                  ("cv2.txt", "32x32 | 30 mcs | 5000 samples")]

list_of_files = [("m.txt",  "16x16 | 300 initial mcs | 30 mcs | 100 samples"),
                 ("m2.txt", "100x100 | 150 initial mcs | 30 mcs | 50 samples")]

datalist = [ ( pylab.loadtxt(filename), label ) for filename, label in list_of_files ]

for data, label in datalist:
    pylab.plot( data[:,0], data[:,1], label=label )

#pylab.legend()
# pylab.title("")
pylab.xlabel("kT/J")
pylab.ylabel("Average Magnetization Per Spin")
pylab.legend()
pylab.grid();

pylab.show()