import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.distance import cdist

fname = "markers.td"
# Read all frames from 'markers.td'.
frames = np.loadtxt(fname, skiprows=1, usecols=range(1,49))

dist = cdist(frames, frames, "euclidean")

# Display matrix
plt.matshow(dist,cmap=plt.cm.gray_r)

plt.show()