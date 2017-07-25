

```python
from time import time

def logged(when):
    def log(f, *args, **kargs):
        print '''Called:
        function: %s
        args: %r
        kargs: %r''' % (f, args, kargs)
        
    def pre_logged(f):
        def wrapper(*args, **kargs):
            log(f, args, kargs)
            return f(args, kargs)
        return wrapper
    
    def post_logged(f):
        def wrapper(*args, **kargs):
            now = time()
            try:
                return f(args, kargs)
            finally:
                log(f, args, kargs)
                print "time delta: %s" % (time() - now)
        return wrapper
    
    try:
        return {"pre": pre_logged, "post": post_logged}[when]
    except KeyError, e:
        raise ValueError(e), 'must be "pre" or "post"'

@logged("post")
def hello(name):
    print "Hello", name

hello("World!")
```

    Called:
            function: <function hello at 0x109239b18>
            args: (('World!',), {})
            kargs: {}
    time delta: 0.00108003616333
    


    ---------------------------------------------------------------------------

    TypeError                                 Traceback (most recent call last)

    <ipython-input-5-87691b3c8a9d> in <module>()
         33     print "Hello", name
         34 
    ---> 35 hello("World!")
    

    <ipython-input-5-87691b3c8a9d> in wrapper(*args, **kargs)
         18             now = time()
         19             try:
    ---> 20                 return f(args, kargs)
         21             finally:
         22                 log(f, args, kargs)
    

    TypeError: hello() takes exactly 1 argument (2 given)

