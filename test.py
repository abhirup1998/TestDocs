import time
import numpy as np
N = 102400

x = np.linspace(0.0123, 4567.89, N)

def mine(x,Z,func,name):

  print (name);

  start = time.time()

  for z in range ( 0, Z ) :

    y = func(x);

  end = time.time()

  print (N, Z, end - start)

  return

mine(x,10000,np.sin,'np.sin')

mine(x,10000,np.cos,'np.cos')

mine(x,10000,np.tan,'np.tan')
