import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class RemetenteCalculadora {
    public static void main(String[] args) {
        final String SERVER_IP = "127.0.0.1";
        final int SERVER_PORT = 55555;

        try (DatagramSocket socket = new DatagramSocket();
             Scanner scanner = new Scanner(System.in)) {

            System.out.println("Digite a opção desejada:");
            System.out.println("1 - SOMA");
            System.out.println("2 - SUBTRAÇÃO");
            System.out.println("3 - DIVISÃO");
            System.out.println("4 - MULTIPLICAÇÃO");
            System.out.println("0 - SAIR\n");

            String op = scanner.nextLine();
            if (op.equals("0")) {
                System.out.println("Saindo...");
                return;
            }

            System.out.print("Digite um número: ");
            String num1 = scanner.nextLine();

            System.out.print("Digite o outro número: ");
            String num2 = scanner.nextLine();

            // Monta mensagem no formato esperado
            String mensagem = op + ";" + num1 + ";" + num2;
            byte[] buffer = mensagem.getBytes();

            InetAddress serverAddress = InetAddress.getByName(SERVER_IP);

            // Envia pacote para o servidor
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, serverAddress, SERVER_PORT);
            socket.send(packet);
            System.out.println("Mensagem enviada: " + mensagem);

            // Recebe resposta do servidor
            byte[] respostaBuffer = new byte[1024];
            DatagramPacket respostaPacket = new DatagramPacket(respostaBuffer, respostaBuffer.length);
            socket.receive(respostaPacket);

            String resposta = new String(respostaPacket.getData(), 0, respostaPacket.getLength());
            System.out.println("Resposta do servidor: " + resposta);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
