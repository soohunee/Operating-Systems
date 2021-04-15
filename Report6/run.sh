for policy in 'OPT' 'FIFO' 'LRU' 'RAND' 'CLOCK'
do
	for i in 1 2 3 4 5
	do
		python3 paging-policy.py -f VPN_reference.txt --policy=$policy --cachesize=$i -c >> result.txt
	done
done
