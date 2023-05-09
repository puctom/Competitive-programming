import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    private static long p = 41;
    private static long m = 1_000_000_123;
    private static HashMap<Long, String> checkMap = new HashMap<>();
    private static long[] pow = new long[600005];

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                if(st.hasMoreTokens()){
                    str = st.nextToken("\n");
                }
                else{
                    str = br.readLine();
                }
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {

        FastReader scanner = new FastReader();
        TreeSet<Long> hashes = new TreeSet<>();
        calculatePowers();
        int numberOfGiven, numberOfQueried;
        numberOfGiven = scanner.nextInt();
        numberOfQueried = Integer.parseInt(scanner.nextLine().trim());
        for(int i=0;i<numberOfGiven;i++) {
            String s = scanner.nextLine();
            s = "#"+s;
            hashes.add(calculateHash(s));
        }

          //  System.out.println(hashes);
       // System.out.println(checkMap);
        for(int j=0;j<numberOfQueried; j++) {
            String queriedWord = scanner.nextLine();
            queriedWord = "#"  + queriedWord;
            Long hash = calculateHash(queriedWord);
         //   System.out.println("Hash of queried word: " + queriedWord + " is: "+hash);
            char[] chars = queriedWord.toCharArray();
           // System.out.println(Arrays.toString(chars));
            boolean hashFound = false;
            searchSolution:
            for(int i=chars.length-1;i>0;i--) {
                char currentChar = queriedWord.charAt(chars.length-i);
                long modifiedHash;
                String modifiedWord;
              //  System.out.println("We will consider change at position: " + (chars.length-i) + " so char: " + currentChar);
                switch (currentChar) {
                    case 'a':
                        modifiedHash = (hash - pow[i-1] + 2L*pow[i-1])%m;
                      //  System.out.println("1. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'b' +
                                    queriedWord.substring(chars.length-i+1);

                          //  System.out.println(modifiedWord);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {

                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        modifiedHash = (hash - pow[i-1] + 3L*pow[i-1])%m;
                      //  System.out.println("2. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'c' +
                                queriedWord.substring(chars.length-i+1);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {
                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        break;
                    case 'b':
                        modifiedHash = (hash - 2L*pow[i-1] + pow[i-1] + m )%m;
                      //  System.out.println("3. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'a' +
                                    queriedWord.substring(chars.length-i+1);

                         //   System.out.println(modifiedWord);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {
                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        modifiedHash = (hash - 2L*pow[i-1] + 3L*pow[i-1])%m;
                     //   System.out.println("4. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'c' +
                                    queriedWord.substring(chars.length-i+1);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {
                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        break;
                    case 'c':
                        modifiedHash = (2*m + hash - 3L*pow[i-1] + pow[i-1]) % m;
                     //   System.out.println("5. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'a' +
                                    queriedWord.substring(chars.length-i+1);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {
                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        modifiedHash = (m + hash -  3L*pow[i-1] + 2L*pow[i-1]) % m;
                      //  System.out.println("6. option is: " + modifiedHash);
                        if(hashes.contains(modifiedHash)) {
                            modifiedWord = queriedWord.substring(1, chars.length-i) + 'b' +
                                    queriedWord.substring(chars.length-i+1);
                            if(checkMap.get(modifiedHash).equals(modifiedWord)) {
                                System.out.println("YES");
                                hashFound = true;
                                break searchSolution;
                            }
                        }
                        break;
                }
            }

            if(hashFound == false)
                System.out.println("NO");

           // System.out.println("Word " + j + "/" + numberOfQueried);
        }

    }

    private static Long calculateHash(String s) {
      //  System.out.println("Calculating hash of " + s);
        char[] chars = s.toCharArray();
        long hash=0;
        for(int i=1;i<chars.length;i++) {
            hash = (hash*p + (chars[i] - 'a' +1) )%m;
        }
        checkMap.put(hash, s.substring(1));
        return hash;


    }

    private static void calculatePowers() {
        pow[0] = 1;
        for(int i=1;i<=600_000;i++)
            pow[i] = (pow[i-1]*p)%m;
    }
}