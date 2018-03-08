import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial.distance import cdist

# Read all frames from 'markers.td'.
fname = "markers.td"
frames = np.loadtxt(fname, skiprows=1, usecols=range(1,49))
# Exact translation vector and rotation vector respectively
translate = np.zeros((669, 24))
rotate    = np.zeros((669, 24))

translate[:,  ::3] = frames[:,  ::6]
translate[:, 1::3] = frames[:, 1::6]
translate[:, 2::3] = frames[:, 2::6]

rotate[:,  ::3] = frames[:, 3::6]
rotate[:, 1::3] = frames[:, 4::6]
rotate[:, 2::3] = frames[:, 5::6]

# Calculate the distance matrix of which between each 2 translation vectors
dist_trans = cdist(translate, translate, "euclidean")
# Computes the cosine distance between each two of rotation vectors.
dist_rots  = cdist(rotate, rotate, "cosine")
# Computes the distance defined as (Ta - Tb)*(Ra - Rb) which derived from
# 'Interactive Motion Generation from Examples' by Okan Arikan and D. A. Forsyth
dist_combine = cdist(dist_trans * dist_rots, dist_trans * dist_rots, "euclidean")

# Display matrix with only on parameter translation
plt.matshow(dist_trans, cmap=plt.cm.gray_r)
plt.show()

# Display matrix derived from Okan Arikan and D. A. Forsyth's work.
plt.matshow(dist_combine, cmap=plt.cm.gray_r)
plt.show()
