fn main() {
    println!("Hello, from cargo!");

    cc::Build::new()
        .file("../mylist/src/list.c")
        .include("../mylist/include")
        .compile("mylist");
}


fn calcular_factorial(number:u128) -> u128 {

	if number == 0 || number == 1{
		return 1;
	}
	else{
		let mut result:u128 = number;

		for i in (1..number).rev(){
			result = result * i;
		}
		return result;
	}

}


fn es_primo(numero:u128) -> bool{

    let mut es_primo:bool = true;
    let num:f64 = numero as f64;

    if numero > 1{
        


        for i in 2..((num.sqrt() as i128) + 1) {

            if (numero as i128) % i == 0{
                es_primo=false;
                //println!("NO ES PRIMO");
                break;
            }
        }
    }
    //println!("ES PRIMO");
    return es_primo;


}