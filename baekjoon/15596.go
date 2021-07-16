package main

func sum(a []int) (ret int) {
	var ret int
	for _, val := range a {
		ret += val
	}
	return ret
}
