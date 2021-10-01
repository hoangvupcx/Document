function giaiBac1() {
    var a = document.getElementById("aId").value // a đang chứa giá trị có id = aId
    var b = document.getElementById("bId").value

    a = parseFloat(a) // Ép về kiểu số
    b = parseFloat(b)

    if (a == 0)
        {
            if (b == 0)
                alert("Phương trình vô số nghiệm")
            else
                alert("Phương trình vô nghiệm")
        }
    else
        alert("Nghiệm của phương trình la: x = " + (-b/a))
}