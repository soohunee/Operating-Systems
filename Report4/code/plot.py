from matplotlib import pyplot as plt

file = open("result.txt", "r")
List = list()
for line in file:
	line = line[:-2]
	List.append(int(float(line)*100000000))
Nlist = list()
for i in range(12):
	Nlist.append(str(pow(2,i)))

print(List)
print(Nlist)
plt.plot(Nlist, List, marker='o', color='orange')
plt.title('TLB Size Measurement')
plt.xlabel('Number Of Pages')
plt.ylabel('Time Per Access (ns)')
plt.xticks(Nlist)
plt.show()

