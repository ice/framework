
namespace Ice\Filter;

class Js
{

    public function sanitize(string js)
    {
        string min = "";
        char c;
        int i;
        char next;

        for i, c in js {
            let next = js[i],
                min .= c;
        }
        
        return min;
    }
}
