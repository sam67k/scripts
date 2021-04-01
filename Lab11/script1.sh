
#!/bin/bash

let "sum= $1+$2"
let "dif= $1-$2"
let "product= $1*$2"
let "division= $1/$2"

echo -e "\nSum: $sum"
echo "Difference: $dif"
echo "Product: $product"
echo -e "Division: $division\n"
