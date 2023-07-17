pipeline {
  agent{
    dockerfile {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }

  stages {
    stage('SCM'){
      steps{
        checkout(
          [
            $class: 'GitSCM',
            branches: scm.branches,
            userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }

    stage('Build'){
      steps {
        cmakeBuild(
          installation: 'InSearchPath',
          buildDir: "build",
          sourceDir: "src",
          withCmake: true,
          steps: []
        )
      }
    }
    
    stage('Test'){
      steps{
        echo "Testing placeholder"
      }
    }
    
    stage('Deploy'){
      steps{
        echo "Deployment placeholder"
      }
    }
  }
}
