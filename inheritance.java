public class HelloWorld{

     public static void main(String []args){
        System.out.println("Hello World");
     }
}

public interface MyList
{

}

public class InvalidStringException extends Exception
{
    public InvalidStringException()
    {
        super();
    }
}

public class ArrayToList implements MyList
{
    ArrayList<String> arrayToList;

    public ArrayToList()
    {
        arrayToList = new ArrayList<>();
    }

    void convert(String[] a)
    {
        int sz = arrayToList.size();
        for (int i = 0; i < a.length; i++)
        {
            arrayToList.add(a[i));
            System.out.println("I have added the string: "+a[i]+" at the index: "+sz);
            sz = sz + 1;
        }
    }

    void replace(int idx)
    {
        int sz = arrayToList.size();
        if(idx >= 0 && idx < sz)
        {
            System.out.println("I have replaced the string: "+arrayToList[idx]+" with a null string");
            arrayToList.remove(idx);
        }
    }

    public ArrayList<String> compact()
    {
        while(arrayToList.remove("")) {}
        return arrayToList;
    }
}
