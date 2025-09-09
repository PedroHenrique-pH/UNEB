package calculadora;
public class Calculadora {

    // Método para somar dois números
    public double somar(double a, double b) {
        return a + b;
    }

    // Método para subtrair dois números
    public double subtrair(double a, double b) {
        return a - b;
    }

    // Método para multiplicar dois números
    public double multiplicar(double a, double b) {
        return a * b;
    }

    // Método para dividir dois números
    public double dividir(double a, double b) {
        if (b == 0) {
            throw new IllegalArgumentException("Não é possível dividir por zero!");
        }
        return a / b;
    }
}
