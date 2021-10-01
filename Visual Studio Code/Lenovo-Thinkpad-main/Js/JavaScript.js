$(document).ready(function() {

    $('#toggle').click(function() {
        $('nav > ul.menu').slideToggle()
        // $('.accordion').hide("slow")
    })

    $('.search-toggle').click(function() {
        $('.search-box').slideToggle()
    })

    $('.login-and-register').click(function() {
        $('.login-register').slideToggle()
    })

    $("body .body-product:first-child").addClass("wow animate__fadeInLeft")
    $("body .body-product:last-child").addClass("wow animate__fadeInRight")
    $("body .body-product:nth-child(2)").addClass("wow animate__fadeInUp")
    $("body .product-item:nth-child(even) > div").addClass("wow animate__fadeInRight")
    $("body .product-item:nth-child(odd) > div").addClass("wow animate__fadeInLeft")
    $("body ul.menu li a").addClass("wow animate__backInUp")
    
    wow = new WOW(
        {
            boxClass:     'wow',      // default
            animateClass: 'animate__animated', // default
            offset:       0,          // default
            mobile:       true,       // default
            live:         true        // default
        })
    wow.init();

      

    /*$(window).scroll(function() {
        if ($(this).scrollTop() >= $(".picture-product img:last-child").prop('offsetTop') || $(this).scrollTop() <= 0)
        $('.accordion').hide("slow")
        else if ($(this).scrollTop() >= $(".menu-details").prop('offsetTop'))
        $('.accordion').show("slow")
        else 
        $('.accordion').hide("slow")
    })*/

    $(window).scroll(function(event) {
        var pos_body = $('html,body').scrollTop();
        if(pos_body>20){
            $('.gotop').addClass('hien-ra');
        }
        else{
            $('.gotop').removeClass('hien-ra');
        }
    });

    $('.gotop').click(function(event) {
        $('html,body').animate({scrollTop: 0},800);
    });

    $('.gobot').click(function(event) {
        $('html,body').animate({scrollTop: $(".Detail-product").prop('offsetTop')},800);
    });

    $('.accordion-item1.active .accordion-body1').slideDown();
    $('.accordion-header1').click(function(){
        $(this).parent().toggleClass('active');
        $(this).parent().children('.accordion-body1').slideToggle(); // Từ header tìm về cha (item) rồi đưa về con (body)
    })

    $('#btnSearch').click(function() {
        var k = $('#kw').val()
        $(`div.text-product p:contains(${k})`).parent().parent().css("background-color", "#d5d3cd")
        $(`div.text-product pre:contains(${k})`).parent().parent().css("background-color", "#d5d3cd")
    })
    

});

