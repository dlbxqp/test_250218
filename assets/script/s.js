{
    const root = document.querySelector('#root')
    const aside = document.querySelector('#aside')


    const getDescription = ($id) => {
        fetch('/?object_id=' + $id)
        .then(response => response.json())
        .then((response) => {
            aside.textContent = response.description
            aside.classList.add('active')
        })
        .catch((error) => console.log('error', error))
    }

    const getChilrens = (parent= 0)=> {
        fetch('/?parent_id=' + parent)
        .then(response => response.json())
        .then((response) => {
            response.forEach((object) => {
                const div = document.createElement('div')
                div.classList.add('object')

                const title = document.createElement('h2')
                title.addEventListener('click', (e) => {
                    e.preventDefault()

                    getDescription(object.id)
                })
                title.classList.add('title')
                title.textContent = object.title
                div.append(title)

                fetch('/?parent_id=' + object.id)
                .then(response => response.json())
                .then((respnose) => {
                    if(parent === 0 || respnose.length > 0) {
                        const button = document.createElement('button')
                        button.addEventListener('click', (e) => {
                            e.preventDefault()

                            getChilrens(object.id)
                        })
                        button.classList.add('button')
                        button.textContent = '+'
                        div.append(button)
                    }
                })
                .catch((error) => console.log('error', error))

                const output = document.createElement('output')
                output.classList.add('childrens')
                output.classList.add('children_' + object.id)
                div.append(output)

                if(parent > 0){
                    document.querySelector('.children_' + parent).append(div)
                } else{
                    root.append(div)
                }
            })
        })
        .catch((error) => console.log('error', error))
    }
    document.addEventListener('DOMContentLoaded', () => getChilrens(0))
}