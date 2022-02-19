import React from 'react'
import PropTypes from 'prop-types'


const Domino = ({topText, bottomText}) => {
  const onClick = (e) => {
    console.log('click')
  }
  return (
    <button onClick={onClick}>
      <div class="dominoes-tile">
        <div class="dominoes-tile__top">
          <p>{topText}</p>
        </div>
        <div class="dominoes-tile__bottom">
          <p>{bottomText}</p>
        </div>
      </div>
    </button>
  )
}

Domino.defaultProps = {
  topText: 'AB',
  bottomText: 'BC'
}

Domino.prototype = {
  topText: PropTypes.string,
  bottomText: PropTypes.string
}

export default Domino