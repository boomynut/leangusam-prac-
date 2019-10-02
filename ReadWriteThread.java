import java.io.*;

public class ReadWriteThread extends Thread {
    private BufferedReader input;
    private PrintWriter output;
    private String header;

    public ReadWriteThread(InputStream input, OutputStream output, String prefix) {
        this.input = new BufferedReader(new InputStreamReader(input));
        this.output = new PrintWriter(output, true);
        this.header = prefix;
    }

    public ReadWriteThread(InputStream input, OutputStream output) {
        this(input, output, "");
    }

    public void run() {
        try {
            String line;
            while ((line = input.readLine()) != null){
                output.print(header);
                output.println(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
