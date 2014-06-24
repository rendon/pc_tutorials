import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class Cyberline
{
	public String lastCyberword(String cyberline)
	{
        String[] tokens =  cyberline.replace("-", "").split("[^a-zA-Z0-9@]+");
        return tokens[tokens.length-1];
	}
}


// Edited by VimCoder 0.3.5
// http://github.com/chazmcgarvey/vimcoder