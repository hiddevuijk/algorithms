import numpy as np
import matplotlib.pyplot as plt
N = 4
data = np.loadtxt('out.dat')[:,1]
print(np.mean(data))
print(np.std(data))
print(min(data))
print(min(data)*N*N)
plt.hist(data,bins=100)
plt.show()
