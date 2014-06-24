import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class UnLinker
{
	public String clean(String text)
	{
        String p = "(http://|http://www\\.|www\\.)"
                 + "([a-zA-Z0-9.]+)"
                 + "(\\.com|\\.org|\\.edu|\\.info|\\.tv)";

        Pattern pattern = Pattern.compile(p);
        Matcher matcher = pattern.matcher(text);
        int count = 1;
        while (matcher.find()) {
            int start = matcher.start();
            int end = matcher.end();
            text = text.replaceFirst(matcher.group(), "OMIT" + count);
            count++;
        }

        return text;
    }
}


// Edited by VimCoder 0.3.5
// http://github.com/chazmcgarvey/vimcoder