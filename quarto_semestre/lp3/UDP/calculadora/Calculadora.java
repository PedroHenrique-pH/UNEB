public class Calculadora {

    public double realizar_operacao(double a, double b, int op){
        double resultado = 0;
                
                switch (op) {
                    case 1: 
                        resultado = a + b; 
                        break;

                    case 2: 
                        resultado = a - b;
                        break;

                    case 3:
                        if (b == 0) {
                            throw new IllegalArgumentException("Não é possível dividir por zero!");
                        } else{
                            resultado = a / b;
                        }
                        break;

                    case 4: 
                        resultado = a * b; 
                        break;

                    default:
                        System.out.println("Operação inválida!");
                        break;
                }
        return resultado;

    }
}
