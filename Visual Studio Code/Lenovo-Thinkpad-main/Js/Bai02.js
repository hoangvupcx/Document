$(document).ready(function() {
    $("div.items > div.item:nth-child(even)").addClass("wow animate__lightSpeedInLeft")
    $("div.items > div.item:nth-child(odd)").addClass("wow animate__lightSpeedInRight")
    $("div.figures > figure").addClass("wow animate__flipInX")
    $("div.figures > figure").addClass("c4-izmir c4-border-cc-2 c4-gradient-bottom-left c4-image-zoom-in")
    $("div.figures > figure > figcaption").addClass("c4-layout-center-center")

    wow = new WOW(
        {
            boxClass:     'wow',      // default
            animateClass: 'animate__animated', // default
            offset:       0,          // default
            mobile:       true,       // default
            live:         true        // default
        })
      wow.init();

    $("#btnAdd").click(function() {
        var content = $("#contentId").val()
        var date = $("#dateId").val()

        $("div.items").prepend(`
            <div class="item active">
                <div class="col10">
                    <img src="/images/images/lab2/calendar2.png" alt="">
                </div>
                <div class="col70">
                    <p>${content}</p>
                </div>
                <div class="col10">
                    ${date}
                </div>
                <div class="col10">
                    <input type="button" value="Xóa" name="" id="">
                </div>
            </div>
        `)

        setTimeout(function() {
            $("div.item").removeClass("active")
        },2000)
    }) 

    $("div.items").on("click", "div.item input[type=button]", function() {
        if (confirm("Bạn có chắc chắn muốn xóa không?") == true)
            $(this).parent().parent().remove()
    })
})