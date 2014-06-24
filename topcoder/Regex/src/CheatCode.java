import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class CheatCode
{
	public int[] matches(String keyPresses, String[] codes)
	{
        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < codes.length; i++) {
            String code = codes[i];
            String pattern = "^.*";
            int pos = 0;
            while (pos < code.length()) {
                char ch = code.charAt(pos);
                int count = 0;
                while (pos < code.length() && code.charAt(pos) == ch) {
                    pos++;
                    count++;
                }
                pattern += "(" + ch + "{" + count + ",})";
            }
            pattern += ".*$";
            //System.out.println(pattern);

            if (keyPresses.matches(pattern)) {
                result.add(i);
            }
        }


        int[] indexes = new int[result.size()];
        for (int i = 0; i < result.size(); i++)
            indexes[i] = result.get(i);

        return indexes;
	}

}


// Edited by VimCoder 0.3.5
// http://github.com/chazmcgarvey/vimcoder