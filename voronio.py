import sys
import numpy as np
from scipy.spatial import Voronoi, voronoi_plot_2d
from matplotlib import pyplot as plt


coor = np.random.rand(10, 2) 
vor = Voronoi(coor)
plt.scatter(coor[:,0], coor[:,1])
fig = voronoi_plot_2d(vor)
plt.show()


