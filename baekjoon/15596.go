package main

func sum(a []int) (ret int) {
	for _, val := range a {
		ret += val
	}
	return ret
}
