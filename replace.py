# A single function solution for replacing all of the instances of given substring
# without using any string library methods, I realize it is a bit over-complicated
# for what it needs to accomplish and not very elegant at all, using multiple functions
# could clean this up considerably

st = "asxxxav"

def replace(s, rp, replace): # s: the input string, rp: the value being replaced, replace: the value rp will be replaced with
    newstr = []              # a container for the new string that is being put together with the replacements
    inn = False              # Boolean flag for signaling that the
    i = 0                    # Iterator for the while loop
    while i < len(s):        # we set the loop to go until we reach the end of the input string
        k = i                       # iterator to keep main string inside the nested loop in sync with the substring
        for j in rp:                # loop through the replacement string
            if s[k]!=j:             # if the value of the main string is not matching the substring...
                newstr.append(s[i]) # it does not replace it, so we append the original value from the main string
                inn = False         # set the flag to not replace since the values do no math
                break               # break from the nested loop to prevent value duplication
            k+=1                    # iterate this value so that the main and substring values are in sync when checked
            inn = True              # set the flag for replcement if the all the values match
        if inn == True:             # if this flag is set by the nested loop above we replace 'rp' with 'replace'
            newstr.append(replace)  # adding the replacement value to the string being constructed
            i += len(rp)            # important to iterate i by an amount equal to the length of what was just replaced
        else:
            i+=1                    # if there is no replacement, iterated trough the main string normally
    return "".join(newstr)

print st
print replace(st, "x", "XX")
