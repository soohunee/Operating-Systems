VM = open('valgrind_result.txt', 'r')
VPN = open('VPN_reference.txt', 'w')

lines = VM.readlines()
for line in lines:
	if line.startswith('I') or line.startswith(' '):
		VPN.write(str((int("0x" + line[3:11], 16) & 0xfffff000) >> 12) + "\n")

VM.close()
VPN.close()
