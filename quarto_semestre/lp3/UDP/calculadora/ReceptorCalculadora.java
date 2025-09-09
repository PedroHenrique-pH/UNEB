import Calculadora;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class ReceptorCalculadora {
    public static void main(String[] args) {
        final int PORT = 55555;
        Calculadora calc = new Calculadora();

        try (DatagramSocket socket = new DatagramSocket(PORT)) {
            System.out.println("Servidor UDP da Calculadora aguardando...");

            byte[] buffer = new byte[1024];

            while (true) {
                // Recebe pacote
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);

                String recebido = new String(packet.getData(), 0, packet.getLength());
                System.out.println("Recebido: " + recebido);

                // Espera formato: op;num1;num2
                String[] partes = recebido.split(";");
                if (partes.length < 3) {
                    System.out.println("Mensagem inválida!");
                    continue;
                }

                int operacao = Integer.parseInt(partes[0]);
                double num1 = Double.parseDouble(partes[1]);
                double num2 = Double.parseDouble(partes[2]);

                double resultado = 0;
                switch (operacao) {
                    case 1: resultado = calc.somar(num1, num2); break;
                    case 2: resultado = calc.subtrair(num1, num2); break;
                    case 3: resultado = calc.dividir(num1, num2); break;
                    case 4: resultado = calc.multiplicar(num1, num2); break;
                    default:
                        System.out.println("Operação inválida!");
                        continue;
                }

                System.out.println("Resultado: " + resultado);

                // Envia resposta ao cliente
                String resposta = "Resultado: " + resultado;
                byte[] respostaBytes = resposta.getBytes();

                InetAddress endereco = packet.getAddress();
                int portaCliente = packet.getPort();

                DatagramPacket respostaPacket =
                        new DatagramPacket(respostaBytes, respostaBytes.length, endereco, portaCliente);

                socket.send(respostaPacket);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
