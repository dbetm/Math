import java.io.IOException; // para las excepciones que provoca el usuario y no se pueden controlar
import java.util.Scanner;
// Alumno: David Betancourt Montellano
public class CifradoCesar {

	public static void main(String[] args) throws IOException {		
		Scanner cesar = new Scanner(System.in);
		String msj;
		int a, b;
		char opc;
			
		do {
			System.out.println("Escribe tu mensaje: ");
			msj = cesar.nextLine(); //nextLine para leer todo el mensaje en caso de que no sea palabra única
		} while(msj.isEmpty()); //mientras mensaje está vacío
		
		System.out.println("Dame el valor de a: ");
		a = cesar.nextInt();
		System.out.println("Dame el valor de b: ");
		b = cesar.nextInt();
		
		do {
            cesar.nextLine();
            System.out.print("Presione 'C' para cifrar y 'D' para descifrar: ");
            opc = (char) System.in.read(); //lectura de un sólo carácter
        } while (Character.toUpperCase(opc) != 'C' && Character.toUpperCase(opc) != 'D'); 
		cesar.close();
		
        if (Character.toUpperCase(opc) == 'C') { //hará esto en caso de haber elegido 'C'
            System.out.println("Texto cifrado: " + cifrador(msj, a, b)); 
            //manda llamar el método, se incluyen los parámetros, en sí imprime el valor que regresa el método
        } 
        else {
            System.out.println("Texto descifrado: " + descifrador(msj, a, b)); //manda llamar el otro método
        }	
	}
	
public static String cifrador(String msj, int a, int b) {
    StringBuilder cifrado = new StringBuilder(); 
    //StringBuilder clase donde es posible modificar o trabajar con los carácteres a partir de sus métodos
    int position, res;
    String alphabet = "abcdefghijklmnñopqrstuvwxyz";
    String alphabet2 = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    
    for(char c : msj.toCharArray()) { 
    	/*para iterar recorer mi mensaje letra por letra, en cada vuelta le asigna un valor a la variable 'c',
    	del arreglo de carácteres */
    	
    	 if (c >= 'a' && c <= 'z') {
	    	if (c == ' ') {
	    		cifrado.append(c); //append asigna a String 'cifrado' el valor de 'c'
	    		continue;
	    	}
	    	else {
	    	position = alphabet.indexOf(c); //para encontrar 'p' de (ap + b) mod 27
	    	//el método indexOf devuelve la posición que le corresponde a 'c' en el abecedario
	    	res = alphabet.charAt((a * position + b) % 27); 
	    	//res será la posición de la letra que le corresponde en el abecedario
	    	cifrado.append((char) res); /*hacemos un cast para que 'res' (int) cambie a tipo char
	    	regrese el el carácter y con append se lo asigne a nuestro String 'cifrado' */
	    	}
    	 }
    	 else {
    		 if (c == ' ') {
 	    		cifrado.append(c); 
 	    		continue;
 	    	}
 	    	else {
 	    	position = alphabet2.indexOf(c);
 	    	res = alphabet2.charAt((a * position + b) % 27);
 	    	cifrado.append((char) res); 
 	    	} 
    	 }
     }
     return cifrado.toString();
  }

public static String descifrador(String msj, int a, int b) {
    StringBuilder descifrado = new StringBuilder();
    int position, res, aux;
    String alphabet = "abcdefghijklmnñopqrstuvwxyz"; 
    String alphabet2 = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    
    for(char c : msj.toCharArray()) {
    	int cont = 0;
    	
    	if (c >= 'a' && c <= 'z') {
		    	if (c == ' ') {
		    		descifrado.append(c); 
		    		continue;
		    	}
		    	else {
		    		position = alphabet.indexOf(c);
		    	
			    	while (cont <= 27) {
			    		aux = ((a * cont) + b) % 27;
			    		if (aux == position) {
			    			break;
			    		}
			    		cont++;	
		    	  }
			    	res = alphabet.charAt(cont);
			    	descifrado.append((char)res);
		       }
    	}
    	else {
    		if (c == ' ') {
	    		descifrado.append(c); 
	    		continue;
	    	}
	    	else {
	    		position = alphabet2.indexOf(c);
	    		
		    	while (cont <= 27) {
		    		aux = ((a * cont) + b) % 27;
		    		if (aux == position) {
		    			break;
		    		}
		    		cont++;	
	    	  }
		    	res = alphabet2.charAt(cont);
		    	descifrado.append((char)res);
	       }
    	}
     }
     return descifrado.toString();
  }
}
