import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
  public static void main(String[] args) {
    Kattio io = new Kattio(System.in, System.out);

    while (io.hasMoreTokens()) {
      int n = io.getInt();

      if (n == -1) break;

      io.println("Round " + n);
      io.println(judge(io.getWord(), io.getWord()));
    }

    io.close();
  }

  private enum CharacterState {
    NOT_IN_ANSWER,
    NOT_GUESSED,
    GUESSED
  }

  private static String judge(String answer, String guess) {
    CharacterState states[] = new CharacterState[26];
    Arrays.fill(states, CharacterState.NOT_IN_ANSWER);

    final int numChactersToGuess;

    {
      int count = 0;

      for (int i = 0; i < answer.length(); ++i) {
        if (states[answer.charAt(i) - 'a'] == CharacterState.NOT_IN_ANSWER) {
          ++count;
          states[answer.charAt(i) - 'a'] = CharacterState.NOT_GUESSED;
        }
      }

      numChactersToGuess = count;
    }

    int numCorrectGuesses = 0;
    int numIncorrectGuesses = 0;

    for (int i = 0; i < guess.length(); ++i) {
      if (states[guess.charAt(i) - 'a'] == CharacterState.NOT_IN_ANSWER) {
        if (++numIncorrectGuesses == 7) return "You lose.";
      } else if (states[guess.charAt(i) - 'a'] == CharacterState.NOT_GUESSED) {
        states[guess.charAt(i) - 'a'] = CharacterState.GUESSED;

        if (++numCorrectGuesses == numChactersToGuess) return "You win.";
      }
    }

    return "You chickened out.";
  }
}

/** Simple yet moderately fast I/O routines.
 *
 * Example usage:
 *
 * Kattio io = new Kattio(System.in, System.out);
 *
 * while (io.hasMoreTokens()) {
 *    int n = io.getInt();
 *    double d = io.getDouble();
 *    double ans = d*n;
 *
 *    io.println("Answer: " + ans);
 * }
 *
 * io.close();
 *
 *
 * Some notes:
 *
 * - When done, you should always do io.close() or io.flush() on the
 *   Kattio-instance, otherwise, you may lose output.
 *
 * - The getInt(), getDouble(), and getLong() methods will throw an
 *   exception if there is no more data in the input, so it is generally
 *   a good idea to use hasMoreTokens() to check for end-of-file.
 *
 * @author: Kattis
 */

class Kattio extends PrintWriter {
  public Kattio(InputStream i) {
    super(new BufferedOutputStream(System.out));

    r = new BufferedReader(new InputStreamReader(i));
  }

  public Kattio(InputStream i, OutputStream o) {
    super(new BufferedOutputStream(o));

    r = new BufferedReader(new InputStreamReader(i));
  }

  public boolean hasMoreTokens() {
    return peekToken() != null;
  }

  public int getInt() {
    return Integer.parseInt(nextToken());
  }

  public double getDouble() {
    return Double.parseDouble(nextToken());
  }

  public long getLong() {
    return Long.parseLong(nextToken());
  }

  public String getWord() {
    return nextToken();
  }

  private BufferedReader r;
  private String line;
  private StringTokenizer st;
  private String token;

  private String peekToken() {
    if (token == null)
      try {
        while (st == null || !st.hasMoreTokens()) {
          line = r.readLine();
          if (line == null) return null;
          st = new StringTokenizer(line);
        }

        token = st.nextToken();
      } catch (IOException e) {}

    return token;
  }

  private String nextToken() {
    String ans = peekToken();
    token = null;

    return ans;
  }
}
