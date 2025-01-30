#include <string.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


#define SMAZ_DEBUG
#define SMAZPRINTF printf

/* Our compression codebook, used for compression */
static char *Smaz_cb[241] = {
"\002s,\266", "\003had\232\002leW", "\003on \216", "", "\001yS",
"\002ma\255\002li\227", "\003or \260", "", "\002ll\230\003s t\277",
"\004fromg\002mel", "", "\003its\332", "\001z\333", "\003ingF", "\001>\336",
"\001 \000\003   (\002nc\344", "\002nd=\003 on\312",
"\002ne\213\003hat\276\003re q", "", "\002ngT\003herz\004have\306\003s o\225",
"", "\003ionk\003s a\254\002ly\352", "\003hisL\003 inN\003 be\252", "",
"\003 fo\325\003 of \003 ha\311", "", "\002of\005",
"\003 co\241\002no\267\003 ma\370", "", "", "\003 cl\356\003enta\003 an7",
"\002ns\300\001\"e", "\003n t\217\002ntP\003s, \205",
"\002pe\320\003 we\351\002om\223", "\002on\037", "", "\002y G", "\003 wa\271",
"\003 re\321\002or*", "", "\002=\"\251\002ot\337", "\003forD\002ou[",
"\003 toR", "\003 th\r", "\003 it\366",
"\003but\261\002ra\202\003 wi\363\002</\361", "\003 wh\237", "\002  4",
"\003nd ?", "\002re!", "", "\003ng c", "",
"\003ly \307\003ass\323\001a\004\002rir", "", "", "", "\002se_", "\003of \"",
"\003div\364\002ros\003ere\240", "", "\002ta\310\001bZ\002si\324", "",
"\003and\a\002rs\335", "\002rt\362", "\002teE", "\003ati\316", "\002so\263",
"\002th\021", "\002tiJ\001c\034\003allp", "\003ate\345", "\002ss\246",
"\002stM", "", "\002><\346", "\002to\024", "\003arew", "\001d\030",
"\002tr\303", "", "\001\n1\003 a \222", "\003f tv\002veo", "\002un\340", "",
"\003e o\242", "\002a \243\002wa\326\001e\002", "\002ur\226\003e a\274",
"\002us\244\003\n\r\n\247", "\002ut\304\003e c\373", "\002we\221", "", "",
"\002wh\302", "\001f,", "", "", "", "\003d t\206", "", "", "\003th \343",
"\001g;", "", "", "\001\r9\003e s\265", "\003e t\234", "", "\003to Y",
"\003e\r\n\236", "\002d \036\001h\022", "", "\001,Q", "\002 a\031", "\002 b^",
"\002\r\n\025\002 cI", "\002 d\245", "\002 e\253", "\002 fh\001i\b\002e \v",
"", "\002 hU\001-\314", "\002 i8", "", "", "\002 l\315", "\002 m{",
"\002f :\002 n\354", "\002 o\035", "\002 p}\001.n\003\r\n\r\250", "",
"\002 r\275", "\002 s>", "\002 t\016", "", "\002g \235\005which+\003whi\367",
"\002 w5", "\001/\305", "\003as \214", "\003at \207", "", "\003who\331", "",
"\001l\026\002h \212", "", "\002, $", "", "\004withV", "", "", "", "\001m-", "",
"", "\002ac\357", "\002ad\350", "\003TheH", "", "", "\004this\233\001n\t",
"", "\002. y", "", "\002alX\003e, \365", "\003tio\215\002be\\",
"\002an\032\003ver\347", "", "\004that0\003tha\313\001o\006", "\003was2",
"\002arO", "\002as.", "\002at'\003the\001\004they\200\005there\322\005theird",
"\002ce\210", "\004were]", "", "\002ch\231\002l \264\001p<", "", "",
"\003one\256", "", "\003he \023\002dej", "\003ter\270", "\002cou", "",
"\002by\177\002di\201\002eax", "", "\002ec\327", "\002edB", "\002ee\353", "",
"", "\001r\f\002n )", "", "", "", "\002el\262", "", "\003in i\002en3", "",
"\002o `\001s\n", "", "\002er\033", "\003is t\002es6", "", "\002ge\371",
"\004.com\375", "\002fo\334\003our\330", "\003ch \301\001t\003", "\002hab", "",
"\003men\374", "", "\002he\020", "", "", "\001u&", "\002hif", "",
"\003not\204\002ic\203", "\003ed @\002id\355", "", "", "\002ho\273",
"\002r K\001vm", "", "", "", "\003t t\257\002il\360", "\002im\342",
"\003en \317\002in\017", "\002io\220", "\002s \027\001wA", "", "\003er |",
"\003es ~\002is%", "\002it/", "", "\002iv\272", "",
"\002t #\ahttp://C\001x\372", "\002la\211", "\001<\341", "\003, a\224"
};

/* Reverse compression codebook, used for decompression */
static char *Smaz_rcb[254] = {
" ", "the", "e", "t", "a", "of", "o", "and", "i", "n", "s", "e ", "r", " th",
" t", "in", "he", "th", "h", "he ", "to", "\r\n", "l", "s ", "d", " a", "an",
"er", "c", " o", "d ", "on", " of", "re", "of ", "t ", ", ", "is", "u", "at",
"   ", "n ", "or", "which", "f", "m", "as", "it", "that", "\n", "was", "en",
"  ", " w", "es", " an", " i", "\r", "f ", "g", "p", "nd", " s", "nd ", "ed ",
"w", "ed", "http://", "for", "te", "ing", "y ", "The", " c", "ti", "r ", "his",
"st", " in", "ar", "nt", ",", " to", "y", "ng", " h", "with", "le", "al", "to ",
"b", "ou", "be", "were", " b", "se", "o ", "ent", "ha", "ng ", "their", "\"",
"hi", "from", " f", "in ", "de", "ion", "me", "v", ".", "ve", "all", "re ",
"ri", "ro", "is ", "co", "f t", "are", "ea", ". ", "her", " m", "er ", " p",
"es ", "by", "they", "di", "ra", "ic", "not", "s, ", "d t", "at ", "ce", "la",
"h ", "ne", "as ", "tio", "on ", "n t", "io", "we", " a ", "om", ", a", "s o",
"ur", "li", "ll", "ch", "had", "this", "e t", "g ", "e\r\n", " wh", "ere",
" co", "e o", "a ", "us", " d", "ss", "\n\r\n", "\r\n\r", "=\"", " be", " e",
"s a", "ma", "one", "t t", "or ", "but", "el", "so", "l ", "e s", "s,", "no",
"ter", " wa", "iv", "ho", "e a", " r", "hat", "s t", "ns", "ch ", "wh", "tr",
"ut", "/", "have", "ly ", "ta", " ha", " on", "tha", "-", " l", "ati", "en ",
"pe", " re", "there", "ass", "si", " fo", "wa", "ec", "our", "who", "its", "z",
"fo", "rs", ">", "ot", "un", "<", "im", "th ", "nc", "ate", "><", "ver", "ad",
" we", "ly", "ee", " n", "id", " cl", "ac", "il", "</", "rt", " wi", "div",
"e, ", " it", "whi", " ma", "ge", "x", "e c", "men", ".com"
};


#ifdef SMAZ_DEBUG /* for checking word frequencies */
    static unsigned int smaz_used[(sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0])) + 1] = {0};
#endif


int smaz_compress(const char *in, int inlen, char *out, int outlen) {
    unsigned int h1,h2,h3=0;
    int verblen = 0, _outlen = outlen;
    char verb[256], *_out = out;

    while(inlen) {
        int j = 7, needed;
        char *flush = NULL;
        char *slot;

        h1 = h2 = in[0]<<3;
        if (inlen > 1) h2 += in[1];
        if (inlen > 2) h3 = h2^in[2];
        if (j > inlen) j = inlen;

        /* Try to lookup substrings into the hash table, starting from the
         * longer to the shorter substrings */
        for (; j > 0; j--) {
            switch(j) {
            case 1: slot = Smaz_cb[h1%241]; break;
            case 2: slot = Smaz_cb[h2%241]; break;
            default: slot = Smaz_cb[h3%241]; break;
            }
            while(slot[0]) {
                if (slot[0] == j && memcmp(slot+1,in,j) == 0) {
                    /* Match found in the hash table,
                     * prepare a verbatim bytes flush if needed */
                    if (verblen) {
                        needed = (verblen == 1) ? 2 : 2+verblen;
                        flush = out;
                        out += needed;
                        outlen -= needed;
                    }
                    /* Emit the byte */
                    if (outlen <= 0) return _outlen+1;
                    out[0] = slot[slot[0]+1];
#ifdef SMAZ_DEBUG
                    unsigned int index = (unsigned char)slot[slot[0]+1];
                    smaz_used[index]++;
#endif
                    out++;
                    outlen--;
                    inlen -= j;
                    in += j;
                    goto out;
                } else {
                    slot += slot[0]+2;
                }
            }
        }
        /* Match not found - add the byte to the verbatim buffer */
        verb[verblen] = in[0];
        verblen++;
        inlen--;
        in++;
out:
        /* Prepare a flush if we reached the flush length limit, and there
         * is not already a pending flush operation. */
        if (!flush && (verblen == 256 || (verblen > 0 && inlen == 0))) {
            needed = (verblen == 1) ? 2 : 2+verblen;
            flush = out;
            out += needed;
            outlen -= needed;
            if (outlen < 0) return _outlen+1;
        }
        /* Perform a verbatim flush if needed */
        if (flush) {
            if (verblen == 1) {
                flush[0] = (signed char)254;
                flush[1] = verb[0];
            } else {
                flush[0] = (signed char)255;
                flush[1] = (signed char)(verblen-1);
                memcpy(flush+2,verb,verblen);
            }
            flush = NULL;
            verblen = 0;
        }
    }
    return out-_out;
}

int smaz_decompress(char *in, int inlen, char *out, int outlen) {
    unsigned char *c = (unsigned char*) in;
    char *_out = out;
    int _outlen = outlen;

    while(inlen) {
        if (*c == 254) {
            /* Verbatim byte */
            if (outlen < 1) return _outlen+1;
            *out = *(c+1);
            out++;
            outlen--;
            c += 2;
            inlen -= 2;
        } else if (*c == 255) {
            /* Verbatim string */
            int len = (*(c+1))+1;
            if (outlen < len) return _outlen+1;
            memcpy(out,c+2,len);
            out += len;
            outlen -= len;
            c += 2+len;
            inlen -= 2+len;
        } else {
            /* Codebook entry */
            char *s = Smaz_rcb[*c];
            int len = strlen(s);

            if (outlen < len) return _outlen+1;
            memcpy(out,s,len);
            out += len;
            outlen -= len;
            c++;
            inlen--;
        }
    }
    return out-_out;
}

/* SMAZ debug functions */
#ifdef SMAZ_DEBUG
static void smaz_print_cb_entry(const char *txt, unsigned int len, unsigned int index)
{
/* Prints the the reverse codebook entries formatted for the codebook
 * uses a small buffer to parse for escape characters and convert them
 * back to plaintext escapes
 * '\000text\000'
 * first octal escape is the length of the word
 * the actual word
 * last octal escape is the index in the reverse codebook
 */

    char emit_buf[64];
    unsigned int p = 0;
    SMAZPRINTF("\\%.03o", len);
    for (unsigned int i= 0; i < len; i++)
    {
        if (p + 3 >= sizeof(emit_buf))
        {
            emit_buf[p] = '\0';
            SMAZPRINTF("%s", emit_buf);
            p = 0;
        }
        char c = txt[i];
        if (NULL == strchr("\r\n\t\f", c))
        {
            emit_buf[p++] = c;
        }
        else
        {
            emit_buf[p++] = '\\';
            if (c == '\r')
                emit_buf[p++] = 'r';
            else if (c == '\n')
                emit_buf[p++] = 'n';
            else if (c == '\t')
                emit_buf[p++] = 't';
            else if (c == '\f')
                emit_buf[p++] = 'f';
        }
    }
    if (p > 0) /* bytes left to flush? */
    {
        emit_buf[p] = '\0';
        SMAZPRINTF("%s", emit_buf);
    }

    SMAZPRINTF("\\%.03o", index);
}

static size_t smaz_debug_print_rcb(void)
{
/* Prints the the reverse codebook entries formatted for the codebook */
    unsigned int i;
    unsigned int rcb_count = (sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0]));
    unsigned int rcb_empty = 0;
    size_t bytes_used = 0;
    const char *trcb;

    SMAZPRINTF("\n\n Reverse Codebook:\n\n");
    SMAZPRINTF("[index](octal) 'reverse code' [\\lenReverse_code\\idx]\n");
    trcb = Smaz_rcb[0];

    for (i = 0; i < rcb_count; i++)
    {
        trcb = Smaz_rcb[i];

        if (!trcb || !*trcb)
        {
            rcb_empty++;
            SMAZPRINTF("[%d](\\%.03o) '',\n", i, i);
            bytes_used += 1;
        }

        else
        {
            int inlen = strlen(trcb);
            bytes_used += inlen + 1;
            SMAZPRINTF("[%d](\\%.03o)  [", i, i);
            smaz_print_cb_entry(trcb, inlen, i);
            SMAZPRINTF("],\n");
        }
    }

    SMAZPRINTF("%d entries available\n %ld bytes used\n", rcb_empty, bytes_used);

    return bytes_used;
}

static void smaz_debug_print_word_freq(void)
{
    SMAZPRINTF("\nFrequency Table:\n [index] 'word' (len) x (freq) (used bytes)\n");
    size_t total = 0;
    size_t replaced = 0;
    for (unsigned int i = 0; i < (sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0])); i++)
    {
        size_t len = strlen(Smaz_rcb[i]);
        size_t used = smaz_used[i];
        if (used > 0)
        {
            SMAZPRINTF("\t[%d] '%s'\t (%ld) x (%lu) - 1 = [%ld]\n",
                       i, Smaz_rcb[i], len, used, (len * used - 1) - 2);
            total += (len * used - 1) - 1; /*+NULL byte*/
            replaced += (len * used) - 1;
        }
        else
        {
            SMAZPRINTF("\t[%d] '%s'\t (%ld) x (%d) - 1 = [%ld]\n",
                       i, Smaz_rcb[i], len, 0, -(len + 1));
            total -= (len + 2); /*+NULL + verbatim byte marker */
        }
    }
    SMAZPRINTF("Total bytes saved: %ld replaced total: %ld\n\n", total, replaced);
}

static void smaz_debug_current_codebook(void)
{
    #define MODSZ(c) (c%cb_count)
    unsigned int cb_count = (sizeof(Smaz_cb)/sizeof(Smaz_cb[0]));
    unsigned int rcb_count = (sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0]));

    #define SMAZHASH(ha1, ha2, ha3, txt, len) \
    {                                         \
        ha3 =0; ha1 = ha2 = ((txt)[0])<<3;     \
        if (len > 1) ha2 += (txt)[1];         \
        if (len > 2) ha3 = (ha2)^(txt)[2];    \
    }

    unsigned int i, j;
    const char *trcb;
    size_t cbe_len;

    SMAZPRINTF("\n\n Current Codebook:\n\n");
    SMAZPRINTF("'codebook' [index](octal) 'reverse'\n");
    for (i = 0; i < cb_count; i++)
    {
        const unsigned char *cb = Smaz_cb[i];
        if (!cb)
        {
            SMAZPRINTF("ERROR [%d] NULL entry!\n", i);
            continue;
        }
        cbe_len = strlen(cb);
        /*SMAZPRINTF("Next: %s, len: %d\n", cb, cbe_len);*/
continue_dump:
        const char *rcb = NULL;
        if (!cb || !cb[0])
        {
            SMAZPRINTF("[%d] '',\n", i);
            continue;
        }
        unsigned int cb_len = *cb;
        for (j = 0; j < rcb_count; j++)
        {
            trcb = Smaz_rcb[j];
            if (!trcb[0])
                continue;

            const unsigned char*match = strstr(cb+1, trcb);

            if (match != NULL && match - cb <= cb_len && *(match - 1) == cb_len)
            {
                rcb = Smaz_rcb[j];
                if (cb_len != strlen(rcb))
                    continue;
                unsigned int inlen = strlen(rcb);
                unsigned int h1,h2,h3;
                unsigned int hash = 0;

                SMAZHASH(h1, h2, h3, rcb, inlen);

                if (inlen >= 3)
                    hash = MODSZ(h3);
                else if (inlen >= 2)
                    hash = MODSZ(h2);
                else if (inlen > 0)
                    hash = MODSZ(h1);

                if (hash != i)
                {
                    SMAZPRINTF("ERROR! [%d] '%s' index mismatch [%d] != hash [%d] of '%s',\n",
                               i, cb+1, i, hash, rcb);
                    continue;
                }
                break;
            }
        }

        if (rcb)
        {
            if (cb_len != strlen(rcb))
            {
                SMAZPRINTF("ERROR! [%d] '%s' [%d] != [%ld] '%s',\n",
                           i, cb+1, *cb, strlen(rcb), rcb);
                continue;
            }
            unsigned int cb_index = cb[cb_len+1];
            if (cb_index != j)
            {
                SMAZPRINTF("%d '%s'", cb_len, cb);
                SMAZPRINTF("ERROR! [%d] '%s' index mismatch [%d] != [%d] '%s',\n",
                           i, cb+1, cb_index, j, rcb);
                continue;
            }
            SMAZPRINTF("[%d] '%.*s' [%d](\\%.03o) '%s',\n",
                       i, cb_len, cb+1, j, j, rcb);

            if (cbe_len > cb_len + 2)
            {
                cb+= cb_len + 2;
                cbe_len -= (cb_len + 2); /* to account for the first and last byte */
                goto continue_dump;
            }
        }
        else
        {
            SMAZPRINTF("ERROR ![%d] '%s' [0] '' !NO MATCH!,\n", i, cb+1);
            continue;
        }
    }
#undef MODSZ
#undef SMAZHASH
}

static void smaz_debug(void)
{
    #define MODSZ(c) (c%cb_count)
    unsigned int cb_count = (sizeof(Smaz_cb)/sizeof(Smaz_cb[0]));
    unsigned int rcb_count = (sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0]));
    static bool rcb_found[(sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0]))] = {false};

    #define SMAZHASH(ha1, ha2, ha3, txt, len) \
    {                                         \
        ha3 =0; ha1 = ha2 = ((txt)[0])<<3;     \
        if (len > 1) ha2 += (txt)[1];         \
        if (len > 2) ha3 = (ha2)^(txt)[2];    \
    }
//SMAZPRINTF("inlen: %d h1:%d h2:%d h3:%d '%s'\n", len, MODSZ(ha1), MODSZ(ha2), MODSZ(ha3), txt);
    unsigned int i, j;
    const char *trcb;
    bool first = true;

    for (i = 0; i < rcb_count; i++)
    {
        rcb_found[i] = false;
    }
    trcb = Smaz_rcb[0];

    for (i = 0; i < rcb_count; i++)
    {
        trcb = Smaz_rcb[i];

        if (!trcb || !*trcb)
        {
            rcb_found[i] = true; /* don't need to check these again */
        }
    }

    for (i = 0; i < rcb_count; i++)
    {
        if (!rcb_found[i])
        {
            if (first)
                SMAZPRINTF("\nGenerated codebook:\n\n[0 ... %d] = \"\",\n", cb_count - 1);
            first = false;
            const char* trcb = Smaz_rcb[i];

            unsigned int inlen = strlen(trcb);
            unsigned int h1,h2,h3;
            SMAZHASH(h1, h2, h3, trcb, inlen);

            if (false && inlen>0)
            {
                SMAZPRINTF("%c %c %c '%s'\n", trcb[0],trcb[1],trcb[2], &trcb[3]);
                SMAZPRINTF("index[%d]'%c' - '%s' h1:%u h2:%u h3:%u \n", i, trcb[0],
                   trcb, MODSZ(h1), MODSZ(h2), MODSZ(h3));
            }
            unsigned int hash = 0;
            if (inlen >= 3)
                hash = MODSZ(h3);
            else if (inlen == 2)
                hash = MODSZ(h2);
            else if (inlen > 0)
                hash = MODSZ(h1);
            else
            {
                continue;
            }


            rcb_found[i] = true;
            /* emit this one */
            SMAZPRINTF("[%d] = \"", hash);
            smaz_print_cb_entry(trcb, inlen, i);

            /* check for others in the same bin*/
            for (j = 0; j < rcb_count; j++)
            {
               if (rcb_found[j])
                    continue;
                const unsigned char* v_trcb = Smaz_rcb[j];

                unsigned int v_inlen = strlen(v_trcb);
                unsigned int v1,v2,v3;
                SMAZHASH(v1, v2, v3, v_trcb, v_inlen);
                unsigned int v_hash = 0;
                if (v_inlen >= 3)
                    v_hash = MODSZ(v3);
                else if (v_inlen == 2)
                    v_hash = MODSZ(v2);
                else if (v_inlen > 0)
                    v_hash = MODSZ(v1);
                else
                {
                    continue;
                }
                if (hash == v_hash)
                {
                    /* emit to the current bin */
                    rcb_found[j] = true;
                    smaz_print_cb_entry(v_trcb, v_inlen, j);
                }

            }
            SMAZPRINTF("\",\n"); /* closing line */
        }
    }

    first = true;
    for (i = 0; i < rcb_count; i++)
    {
        if (!rcb_found[i])
        {
            if (first)
                SMAZPRINTF("\nEntries not referenced by codebook:\n\n");
            first = false;
            const unsigned char* trcb = Smaz_rcb[i];
            SMAZPRINTF("[%d] '%s'\n",i, trcb);
            int inlen = strlen(trcb);
            SMAZPRINTF("[%d](\\%.03o) '%s' [\\%.03o%s\\%.03o],\n",
                       i, i, trcb, inlen, trcb, i);
            unsigned int h1,h2,h3=0;
            h1 = h2 = trcb[0]<<3;
            if (inlen > 1) h2 += trcb[1];
            if (inlen > 2) h3 = h2^trcb[2];

            unsigned int hash = 0;
            if (inlen >= 3)
                hash = MODSZ(h3);
            else if (inlen == 2)
                hash = MODSZ(h2);
            else if (inlen > 0)
                hash = MODSZ(h1);
            else
            {
                continue;
            }
            SMAZPRINTF("match 1[%d][\\%.03o%s\\%.03o]\n", hash, inlen, trcb , i);
        }
    }

    SMAZPRINTF("\n\n");
#undef MODSZ
#undef SMAZHASH
}

int main()
{
    static char *test[10] = {
    "This is a small string",
    "foobar",
    "the end",
    "not-a-g00d-Exampl333",
    "Smaz is a simple compression library",
    "Nothing is more difficult, and therefore more precious, than to be able to decide",
    "this is an example of what works very well with smaz",
    "1000 numbers 2000 will 10 20 30 compress very little",
    "http://programming.reddit.com",
    "http://github.com/antirez/smaz/tree/master",
    };
    
    char c;
    
    smaz_debug_print_rcb();
    printf("Press enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF);
    
    smaz_debug_current_codebook();
    printf("Press enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF);
    
    smaz_debug();
    printf("Press enter to continue\n");
    while ((c = getchar()) != '\n' && c != EOF);


    static char buf[128]; 
    static char buf2[128];
    size_t total = 0;
    size_t total_comp = 0;
    unsigned int rcb_count = (sizeof(Smaz_rcb)/sizeof(Smaz_rcb[0]));
    for (unsigned int i = 0; i < rcb_count + 10; i++)
    {
        const char *word;
        if (i < rcb_count)
            word = Smaz_rcb[i];
        else
            word = test[i-rcb_count];

        if (!word || !*word)
            continue;
        size_t len = strlen(word);
        char* res = buf;
        size_t res_len = smaz_compress(word, len, buf, sizeof(buf));
        if (res_len >= sizeof(buf))
            continue;
        buf[res_len] = '\0';
        total_comp += res_len;
        SMAZPRINTF("In: %ld '%s'\n", len, word);
        SMAZPRINTF("[%d] diff(%ld) len: %lu '%s' len: %lu '%s' \n",
                   i, len - res_len, len, word, res_len, res);

        res_len = smaz_decompress(res, res_len, buf2, sizeof(buf2));
        if (res_len >= sizeof(buf2))
            continue;
        buf2[res_len] = '\0';
        SMAZPRINTF("decoder out: %ld '%s'\n\n", res_len, buf2);
        if (strcmp(word, buf2) != 0)
        {
            SMAZPRINTF("!!BAD MATCH!!@\n\n\n");
            return 0;
        }

        total += len + 1;
    }

    smaz_debug_print_word_freq();


    return 0;
}
#endif
