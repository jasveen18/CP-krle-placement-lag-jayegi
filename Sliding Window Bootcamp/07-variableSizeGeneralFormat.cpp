// ** General Format of Variable Size Format ** //

// Ek baar fix size window ka format ->
// while(j < size) {
// 	calculation

// 	if(window size < k)
// 		j++;

// 	else if(window size == k) {
// 		ans <- calculation
// 		calculation krke remove i

// 		window size ko maintain and slide
// 	}
// }



// Variable size window ke lie ->

// while(j < size) {
// 	calculations

// 	if(condition < k)
// 		j++;

// 	else if(condition == k) {
// 		ans <- calculations
// 		j++;
// 	}

// 	else if(condition > k) {
// 		while( condition > k){
// 			remove calculations for i
// 			i++
// 		}
// 	}
// }