# get_option
parse command line option



## Usage

### Define option data.

#### Defining option by default

```c++
line_option(prefix, name, argument_count)
```

- prefix : prefix of option like -, /
- name : name of option like port, ip
- argumnet_count : max argument number of option

#### Defining option with short name

```c++
line_option(prefix, name, prefix, short_name, argument_count)
```

If you set short name, parser will parse option same as full name. Later, you can get arguments using short name.



### Parse option.

Simply, just create parser with command line arguments and option data.

```c++
parser(argc, argv, options)
```

#### How to parse option?

Let's say you want to parse port and ip option starts with '-'' and each option get only 1 argument. And when program start like this,

```
(program name) -port 8080 -ip 127.0.0.1
```

  You can write like this.

```c++
line_option("-", "port", 1);
line_option("-", "ip", 1);
```

Want to parse with short name? write like this.

```c++
line_option("-", "port", "-", "p", 1);
line_option("-", "ip", "-", "i", 1);
```

And now,  just pass argc, argv and option data to parser's constructor.

```c++ 
int main(int argc, char** argv)
{
    line_option port_option("-", "port", "-", "p", 1);
    line_option ip_option("-", "ip", "-", "i", 1);
    
    parser parser(argc, argv, {
        port_option,
        ip_option
    });
}
```

That's it. After create parser, just get values with option name. Notice that when you get values with option name, option name must contain prefix.

```c++
int main(int argc, char** argv)
{
    line_option port_option("-", "port", "-", "p", 1);
    line_option ip_option("-", "ip", "-", "i", 1);
    
    parser parser(argc, argv, {
        port_option,
        ip_option
    });
    /*
    	This way is dangerous because it can be throw out_of_range.
    	Please just read as example.
    */
    std::vector<std::string> ports = parser.get_arguments("-port");
    std::cout << "port : " << ports[0] << std::endl;

    std::vector<std::string> ip = parser.get_arguments("-ip");
    std::cout << "ip : " << ip[0] << std::endl;
}
```

The result will be like this.

```
port : 8080
ip : 127.0.0.1
```

