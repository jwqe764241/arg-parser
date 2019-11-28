# get-option
parse command line option



## Usage

### 1. Define option data.

#### Defining option by default

```c++
cmd::option(name, argument_count)
```

- name : name of option like -port, -ip, /all, /delete and etc...
- argumnet_count : max argument number of option

#### Defining option with short name

```c++
cmd::option(name, short_name, argument_count)
```

If you set short name, parser will parse option same as full name. Later, you can get arguments using short name.



### 2. Parse option.

Simply, just create parser with command line arguments and option data.

```c++
cmd::parser(argc, argv, options)
```

#### How to parse option?

Let's say you want to parse port and ip option starts with '-'' and each option get only 1 argument. And when program start like this,

```
(program name) -port 8080 -ip 127.0.0.1
```

  You can write like this.

```c++
cmd::option("-port", 1);
cmd::option("-ip", 1);
```

Want to parse with short name? write like this.

```c++
cmd::option("-port", "-p", 1);
cmd::option("-ip", "-i", 1);
```

And now,  just pass argc, argv and option data to parser's constructor.

```c++ 
int main(int argc, char** argv)
{
    cmd::option port_option("-port", "-p", 1);
    cmd::option ip_option("-ip", "-i", 1);
    
    cmd::parser parser(argc, argv, {
        port_option,
        ip_option
    });
}
```

That's it. After create parser, just get values with option name. 

```c++
int main(int argc, char** argv)
{
    cmd::option port_option("-port", "-p", 1);
    cmd::option ip_option("-ip", "-i", 1);
    
    cmd::parser parser(argc, argv, {
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
### How to add this in my project?
Just add files in 'include' folder. This is header only.
