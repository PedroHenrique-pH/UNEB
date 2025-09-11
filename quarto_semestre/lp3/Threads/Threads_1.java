public class Threads_1{
    public static void main(String[] args){
        Thread t0 = new Thread(new MeuRunnable());
        // t0.run(); com run ele usa a Thread principal
        t0.start(); // com o start ele inicializa uma Thread nova

        Thread t1 = new Thread(new MeuRunnable());
        t1.start();

        Thread t2 = new Thread(new MeuRunnable());
        t2.start();
    }
}