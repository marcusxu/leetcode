def minLength(s: str) -> int:
    while('AB' in s or 'CD' in s):
        s=s.replace('AB','')
        s=s.replace('CD','')
    return len(s)

print(minLength('ABFCACDB'))
        