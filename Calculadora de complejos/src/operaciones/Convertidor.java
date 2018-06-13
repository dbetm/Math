package operaciones;

/**
 * Permite convertir un número complejo en su de forma trigonométrica a la
 * algebraica y de la forma exponencial a algebraica.
 *
 * @author dabetm
 */
public abstract class Convertidor {
    
    // INICIA ###### MÉTODOS PARA REPRESENTAR DE LA FORMA TRIGONOMÉTRICA A LA ALGEBRAICA ###

    public static String deTrigonometricaAAlgebraica(String numero) {
        String complejo = "";
        numero = numero.replace(" ", ""); // quitar los espacios en blanco

        // Normalizado es una validación suave
        complejo = isNormalizadoTrigonometrico(numero) ? validarComoExpresionRegular(numero)
                : "Error, expresión inválida.";

        return complejo;
    }

    private static boolean isNormalizadoTrigonometrico(String cadena) {
        boolean tieneCaracteresRaros = false;

        for (int i = 0; i < cadena.length(); i++) {
            if ((int) cadena.charAt(i) != 46 && (int) cadena.charAt(i) != 40
                    && (int) cadena.charAt(i) != 41 && (int) cadena.charAt(i) != 91
                    && (int) cadena.charAt(i) != 93 && ((int) cadena.charAt(i) < 48
                    || (int) cadena.charAt(i) > 57) && (int) cadena.charAt(i) != 105
                    && (int) cadena.charAt(i) != 106 && (int) cadena.charAt(i) != 43
                    && (int) cadena.charAt(i) != 99 && (int) cadena.charAt(i) != 111
                    && (int) cadena.charAt(i) != 115 && (int) cadena.charAt(i) != 101
                    && (int) cadena.charAt(i) != 110 && (int) cadena.charAt(i) != 45) {
                tieneCaracteresRaros = true;
                break;
            }

        }

        // ### FILTROS ###
        // No debe tener caracteres raros
        if (tieneCaracteresRaros) {
            System.out.println("Caracteres raros");
            return false;
        } // El mínimo de carácteres es 14 => cos(1)+isin(0)
        else if (cadena.length() < 14) {
            System.out.println("Longitud");
            return false;
        } // Debe tener un cos y un sin
        else if (!cadena.contains("cos") && (!cadena.contains("sin") || !cadena.contains("sen"))) {
            System.out.println("funciones");
            return false;
        } 
        // Debe tener una i o una j
        else if(!cadena.contains("i") && !cadena.contains("j"))
            return false;
        // Debe tener 6 paréntesis (, ), [, ], si r no es 1 (u omitieron ponerlo)
        else if (((int) cadena.charAt(0) > 47 && (int) cadena.charAt(0) < 58)
                || (int) cadena.charAt(0) == 46 || (int) cadena.charAt(0) == 45) {
            int numParentesis = 0;
            // System.out.println("r diferente de 1");
            for (int i = 0; i < cadena.length(); i++) {
                if ((int) cadena.charAt(i) == 40 || (int) cadena.charAt(i) == 41
                        || (int) cadena.charAt(i) == 91 || (int) cadena.charAt(i) == 93) {
                    numParentesis++;
                }
            }
            if (numParentesis < 6) {
                return false;
            }
        } // Debe tener 4 paréntesis cuando r es 1 y no lo pusieron
        else if ((int) cadena.charAt(0) == 'c') {
            System.out.println("R es 1");
            int numParentesis = 0;
            for (int i = 0; i < cadena.length(); i++) {
                if ((int) cadena.charAt(i) == 40 || (int) cadena.charAt(i) == 41) {
                    numParentesis++;
                }
            }
            if (numParentesis != 4) {
                return false;
            }
        } else {
            System.out.println("Caso default");
            return false;
        }
        return true;
    }

    // Lo que hace es verificar si la cadena cumple con la forma trigonométrica
    // Si es así, construye un String con la forma algebraica
    private static String validarComoExpresionRegular(String numero) {
        String complejo = "", angulo = "", r = "";
        float ang = 1, modulo = 1;
        boolean bandera1 = true, bandera2 = true;
        if (numero.charAt(0) == 'c') {
            r = "1";
            if (numero.charAt(1) == 'o' && numero.charAt(2) == 's' && numero.charAt(3) == '(') {
                int i = 4;
                while (numero.charAt(i) != ')') {
                    if (i > numero.length() - 1) {
                        complejo = "Expresión inválida 1";
                        break;
                    }
                    angulo += numero.charAt(i);
                    i++;
                }
                angulo = angulo.replace("(", "");
                i++;
                if ((numero.charAt(i + 1) == 'i' || numero.charAt(i + 1) == 'j')
                        && numero.charAt(i + 2) == 's' && (numero.charAt(i + 3) == 'i'
                        || numero.charAt(i + 3) == 'e') && numero.charAt(i + 4) == 'n'
                        && numero.charAt(i + 5) == '(') {
                    String angulo2 = "";
                    i += 5;
                    // Para comparar los ángulos
                    while (numero.charAt(i) != ')') {
                        if (i > numero.length() - 1) {
                            complejo = "Expresión inválida 2";
                            break;
                        }
                        angulo2 += numero.charAt(i);
                        i++;
                    }
                    angulo2 = angulo2.replace("(", "");
                    if (!angulo2.equals(angulo))
                        complejo = "Expresión inválida 3";
                } 
                else
                    complejo = "Expresión no válida 4";
            } 
            else
                complejo = "Expresión no válida 5";
        } 
        else {
            int i = 0;
            while (numero.charAt(i) != 'c') {
                if (i > numero.length() - 1) {
                    complejo = "Expresión inválida 6";
                    break;
                }
                r += numero.charAt(i);
                i++;
            }
            if(numero.charAt(i + 1) == 'o' && numero.charAt(i + 2) == 's'
                    && numero.charAt(i + 3) == '(') {
                i += 3;
                while (numero.charAt(i) != ')') {
                    if (i > numero.length() - 1) {
                        complejo = "Expresión inválida 7";
                        break;
                    }
                    angulo += numero.charAt(i);
                    i++;
                }
                angulo = angulo.replace("(", "");
                i++;
                if ((numero.charAt(i + 1) == 'i' || numero.charAt(i + 1) == 'j')
                        && numero.charAt(i + 2) == 's' && (numero.charAt(i + 3) == 'i'
                        || numero.charAt(i + 3) == 'e') && numero.charAt(i + 4) == 'n'
                        && numero.charAt(i + 5) == '(') {
                    String angulo2 = "";
                    i += 5;
                    // Para comparar los ángulos
                    while (numero.charAt(i) != ')') {
                        if (i > numero.length() - 1) {
                            complejo = "Expresión inválida 8";
                            break;
                        }
                        angulo2 += numero.charAt(i);
                        i++;
                    }
                    angulo2 = angulo2.replace("(", "");
                    if (numero.charAt(numero.length() - 1) == ')' && !angulo2.equals(angulo))
                        complejo = "Expresión inválida, los ángulos no coinciden.";
                } 
                else
                    complejo = "Expresión no válida 10";
            } 
            else
                complejo = "Expresión no válida 11";
        }
        angulo = angulo.replace("(", "");
        r = r.replace("(", "");
        r = r.replace("[", "");
        System.out.println("Ángulo: " + angulo + "\nr: " + r);
        System.out.println(complejo);
        
        // que esté vació significa que en teoría no es una
        // expresión inválida.
        if (complejo.isEmpty()) { 
            complejo = conformarConversion(complejo, r, angulo);
        }

        return complejo;
    }
    
    // TERMINA ###### MÉTODOS PARA REPRESENTAR DE LA FORMA TRIGONOMÉTRICA A LA ALGEBRAICA ###
    
    
    // -------------------------------------------------------------------------------------
    
    
    // INICIA ###### MÉTODOS PARA REPRESENTAR DE LA FORMA EXPONENCIAL A LA ALGEBRAICA ###
    
    public static String deExponencialAAlgebraica(String numero) {
        String complejo = "";
        numero = numero.replace(" ", ""); // quitar los espacios en blanco
        numero = numero.replace("*", ""); // quitar los asteriscos

        // Normalizado es una validación suave
        complejo = isNormalizadoExponencial(numero) ? validarExpresionExp(numero)
                : "Error, expresión inválida.";

        return complejo;
    }
    
    private static boolean isNormalizadoExponencial(String cadena) {
        // FILTROS (suaves)
        
        //Carácteres raros
        for (int i = 0; i < cadena.length(); i++) {
            if((int)cadena.charAt(i) != 101 && (int)cadena.charAt(i) != 105 &&
                (int)cadena.charAt(i) != 106 && (int)cadena.charAt(i) != 45 && 
                (int)cadena.charAt(i) != 40 && (int)cadena.charAt(i) != 45 && 
                ((int)cadena.charAt(i) < 48 || (int)cadena.charAt(i) > 57) &&
                (int)cadena.charAt(i) != 46 && (int)cadena.charAt(i) != 94 &&
                (int)cadena.charAt(i) != 41) {
                return false;
            }
        }
        
        //Debe tener e, i y ^
        if(!cadena.contains("e") || !cadena.contains("i") || !cadena.contains("^"))
            return false;
        
        // Mínimo de 3 carácteres e^i
        if(cadena.length() < 3)
            return false;
        
        // r es positivo, así que comienza con un número, '.' o con 'e'
        if((int)cadena.charAt(0) != 101 && ((int)cadena.charAt(0) < 48 || 
                (int)cadena.charAt(0) > 57) && (int)cadena.charAt(0) != 46)
            return false;
            
       return true;
    }
    
    private static String validarExpresionExp(String numero) {
        String solucion = "", angulo = "", r = "";
        float ang = 1, modulo = 1;
        
        if(numero.charAt(0) == 'e') {
            r = "1";
            if(numero.charAt(1) == '^' && (numero.charAt(2) == 'i' || 
                numero.charAt(2) == 'j' || numero.charAt(2) == '(')) {
                if(numero.charAt(2) == 'i' || numero.charAt(2) == 'j') {
                    if(numero.charAt(3) == '(') {
                        int i = 4;
                        while (numero.charAt(i) != ')') {
                            if (i > numero.length() - 1) {
                                solucion = "Expresión inválida 1";
                                break;
                            }
                            angulo += numero.charAt(i);
                            i++;
                        }
                    }
                    else
                        solucion = "Expresión inválida 2";
                }
                else {
                    if(((int)numero.charAt(4) > 47 && (int)numero.charAt(4) < 58) ||
                        numero.charAt(4) == '.') {
                        int i = 4;
                        while (((int)numero.charAt(i) > 47 && (int)numero.charAt(i) < 58)
                            || numero.charAt(i) == '.') {
                            if (i > numero.length() - 1) {
                                solucion = "Expresión inválida 3";
                                break;
                            }
                            angulo += numero.charAt(i);
                            i++;
                        }
                    }
                    else
                        solucion = "Expresión inválida 4";
                }
                    
            }
            else
                solucion = "Expresión inválida 5";
        }
        // Ahora cuando el radio es mayor a 1
        else {
            if(((int)numero.charAt(0) > 47 && (int)numero.charAt(0) < 58) ||
                        numero.charAt(0) == '.') {
                int i = 0;
                while (numero.charAt(i) != 'e') {
                    if (i > numero.length() - 1) {
                        solucion = "Expresión inválida 6";
                        break;
                    }
                    r += numero.charAt(i);
                    i++;
                }
                // -------------------------
                if (numero.charAt(i) == 'e') { // Se va a cumplir
                    if (numero.charAt(i+1) == '^' && (numero.charAt(i+2) == 'i'
                            || numero.charAt(i+2) == 'j' || numero.charAt(i+2) == '(')) {
                        if (numero.charAt(i+2) == 'i' || numero.charAt(i+2) == 'j') {
                            System.out.println(numero.charAt(i+3));
                            if (((int) numero.charAt(i+3) > 47 && (int) numero.charAt(i+3) < 58)
                                    || numero.charAt(i+3) == '.') {
                                i += 3;
                                while (i < numero.length()) {
                                    angulo += numero.charAt(i);
                                    i++;
                                }
                            } else {
                                solucion = "Expresión inválida 8";
                            }
                        } else {
                            i++;
                            System.out.println("=> " + numero.charAt(i+3));
                            if (((int) numero.charAt(i+3) > 47 && (int) numero.charAt(i+3) < 58)
                                    || numero.charAt(i+3) == '.') {
                                i += 3;
                                while (((int) numero.charAt(i) > 47 && (int) numero.charAt(i) < 58)
                                        || numero.charAt(i) == '.') {
                                    if (i > numero.length() - 1) {
                                        solucion = "Expresión inválida 9";
                                        break;
                                    }
                                    angulo += numero.charAt(i);
                                    i++;
                                }
                            } else {
                                solucion = "Expresión inválida 10";
                            }
                        }

                    } else {
                        solucion = "Expresión inválida 11";
                    }
                }
            }
            else 
                solucion = "Expresión inválida 12";
        }
        
        if(solucion.isEmpty()) {
            solucion = conformarConversion(solucion, r, angulo);
        }
        return solucion;
    }
    
    // TERMINA ###### MÉTODOS PARA REPRESENTAR DE LA FORMA EXPONENCIAL A LA ALGEBRAICA ###
    
    
    // ### MÉTODO GENÉRICOS
    
    // Esta función redondea sólo si la diferencia al entero más próximo es menor a 0.05 
    // y si al redondear no da 0
    private static float intelRound(float n) {
        float nRounded = Math.round(n);
        
        if(Math.abs( - nRounded) < 0.05 && nRounded != 0) {
            n = nRounded;
        }
        
        // Si se redondean y queda un valor muy pequeño se representa con 0
        if(n < 0.01) n = 0;
        
        return n;
    }
    
    private static String conformarConversion(String solucion, String r, String angulo) {
        float ang = 1, modulo = 1;
        boolean bandera1 = true, bandera2 = true;
        try {
            modulo = Float.parseFloat(r);
        } 
        catch (Exception e) {
            solucion = "Arg de sin(x) incorrecto";
            bandera1 = false;
        }
        if (bandera1) {
            try {
                ang = (float) Math.toRadians(Float.parseFloat(angulo));
            } 
            catch (Exception e) {
                solucion = "Arg de cos(x) incorrecto";
                bandera2 = false;
            }
        }
        if (bandera1 && bandera2) {
            float x = (float) (modulo * Math.cos(ang));
            //redondeo inteligente
            x = intelRound(x);
            float y = (float) (modulo * Math.sin(ang));
            y = intelRound(y);

            solucion = String.format("%.2f", x);
            solucion += (y < 0) ? "-i" + String.format("%.2f", Math.abs(y))
                    : "+i" + String.format("%.2f", Math.abs(y));
        }
        return solucion;
    }

    // ### TESTEO
    
    public static void main(String[] args) {
        //System.out.println(Convertidor.deTrigonometricaAAlgebraica("-1.41cos(66)+isin(45))"));
        System.out.println(Convertidor.deExponencialAAlgebraica("0.176*e^(i45)"));
    }
}
