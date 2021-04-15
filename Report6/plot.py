from matplotlib import pyplot as plt

#OPT
opt = [51.02, 85.50, 93.06, 95.63, 96.89]
fifo = [51.02, 78.94, 88.33, 92.14, 94.39]
lru = [51.02, 85.25, 90.65, 93.97, 95.46]
rand = [51.02, 78.99, 87.50, 91.51, 93.86]
clock = [51.02, 80.87, 89.17,92.91,94.91]

x= [1,2,3,4,5]
plt.xlabel('Cache size')
plt.ylabel('Hit rate(%)')
plt.plot(x, opt, label='OPT')
plt.plot(x, fifo, label='FIFO')
plt.plot(x, lru, label='LRU')
plt.plot(x, rand, label='RAND')
plt.plot(x, clock, label='CLOCK')
plt.xticks(x)
plt.legend()
plt.show()

