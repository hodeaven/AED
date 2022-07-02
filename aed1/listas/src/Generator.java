import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

    public class Generator
    {
        public static List<Long> randomGenerator(int size) {
            List<Long> list = new ArrayList<Long>(size);
            Random random = new Random();

            while(list.size() < size) {
                Long n = random.nextLong(2 * size);
                if(!list.contains(n))
                    list.add(n);
            }
            return list;
        }

        public static void save(String fileName, List<Long> list ) {
            try {
                FileWriter myWriter = new FileWriter(fileName);
                myWriter.write(list.size() + "\n");
                for (Long l : list) {
                    myWriter.write(l + "\n");
                }

                myWriter.close();
                System.out.println("Successfully wrote to the file.");
            } catch (IOException e) {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }

        }
        public static void main(String[] args) {
            Generator.save("1.000.000.txt", Generator.randomGenerator(1000000));


        }
    }
