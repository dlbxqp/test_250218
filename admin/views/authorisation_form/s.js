const form = document.querySelector('form')
const inputs = form.querySelectorAll('input')
const button = form.querySelector('button')

fillingVerification = () => {
    let result = true

    Array.from(inputs).forEach((input) => {
        if(input.value.length < 4) result = false
    })

    return result
}

Array.from(inputs).forEach((input) => {
    input.addEventListener('input', () => {
        if (fillingVerification() !== false) {
            button.hasAttribute('disabled') && button.removeAttribute('disabled')
        } else {
            !button.hasAttribute('disabled') && button.setAttribute('disabled', 'disabled')
        }
    })
})